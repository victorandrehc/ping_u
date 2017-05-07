const int pin_led=13;
const int unit=500;

const int dot_delay=unit;
const int dash_delay=3*unit;
const int inter_letter_delay=unit;
const int letter_delay=3*unit;
const int word_delay=7*unit;

String msg="Stop Robot Abuse";

void dot();
void dash();
String char2morse(char c);
void morseIt(String c);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin_led, OUTPUT);
  if(msg[msg.length()-1]!=' '){
    msg=msg+" ";
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<msg.length();i++){
    String letter=char2morse(msg[i]);
    Serial.print(letter+" ");
    morseIt(letter);
  }
  Serial.print("\n");
}

void dot(){
  //Serial.println("it is dot");
  digitalWrite(pin_led,HIGH);
  delay(dot_delay);
  digitalWrite(pin_led,LOW);
  delay(inter_letter_delay);
  }

void dash(){
  //Serial.println("it is dash");
  digitalWrite(pin_led,HIGH);
  delay(dash_delay);
  digitalWrite(pin_led,LOW);
  delay(inter_letter_delay);  
}

void morseIt(String c){
  if (c!="/"){
    for(int i=0;i<c.length();i++){
      if(c[i]=='.'){
        dot(); //wait 1 unit
      }else if(c[i]=='-'){
        dash(); //wait 1 unit
      }
    }
    delay(letter_delay-inter_letter_delay);//wait more 2 units, 3 units waited
  }else{
    delay(word_delay-letter_delay); //wait more 4 units, 7 units waited
  }
}

String char2morse(char c){
  switch(c){
    case('A'):
    case('a'):
      return ".-";
      break;
    case('B'):
    case('b'):
      return "-...";
      break;
    case('C'):
    case('c'):
      return "-.-.";
      break;
    case('D'):
    case('d'):
      return "-..";
      break;
    case('E'):
    case('e'):
      return ".";
      break;
    case('F'):
    case('f'):
      return "..-.";
      break;
    case('G'):
    case('g'):
      return "--.";
      break;
    case('H'):
    case('h'):
      return "....";
      break;
    case('I'):
    case('i'):
      return "..";
      break;
    case('J'):
    case('j'):
      return ".---";
      break;
    case('K'):
    case('k'):
      return "-.-";
      break;
    case('L'):
    case('l'):
      return ".-..";
      break;
    case('M'):
    case('m'):
      return "--";
      break;
    case('N'):
    case('n'):
      return "-.";
      break;
    case('O'):
    case('o'):
      return "---";
      break;
    case('P'):
    case('p'):
      return ".--.";
      break;
    case('Q'):
    case('q'):
      return "--.-";
      break;
    case('R'):
    case('r'):
      return ".-.";
      break;
    case('S'):
    case('s'):
      return "...";
      break;
    case('T'):
    case('t'):
      return "-";
      break;
    case('U'):
    case('u'):
      return "..-";
      break;
    case('V'):
    case('v'):
      return "...-";
      break;
    case('W'):
    case('w'):
      return ".--";
      break;
    case('X'):
    case('x'):
      return "-..-";
      break;
    case('Y'):
    case('y'):
      return "-.--";
      break;
    case('Z'):
    case('z'):
      return "--..";
      break;
    case('0'):
      return "-----";
      break;
    case('1'):
      return ".----";
      break;
    case('2'):
      return "..---";
      break;
    case('3'):
      return "...--";
      break;
    case('4'):
      return "....-";
      break;
    case('5'):
      return ".....";
      break;
    case('6'):
      return "-....";
      break;
    case('7'):
      return "--...";
      break;
    case('8'):
      return "---..";
      break;
    case('9'):
      return "----.";
      break;
    default:
      return "/";

  }
}
