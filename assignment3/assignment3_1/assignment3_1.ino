const unsigned long t_measuring=30000;
const unsigned long t_debounce=50;
const int measures_len=3000;
const int unmeasured=-1;

const int light_sensor= A0;
const int push_button= 53;
const int measuring_led=13;
int state=0;
int i=0;
unsigned long t=0,t_aux=0;
int is_button_pressed=0;

int minimum=5000,maximum=-1;
long sum=0;
int n=0;

int measures[measures_len];
unsigned long deltat();
int verify_button();

void setup() {
  // put your setup code here, to run once:
  pinMode(push_button, INPUT);
  pinMode(measuring_led, OUTPUT);
  digitalWrite(measuring_led,LOW);
  Serial.begin(9600);
  for(int i=0;i<measures_len;i++){
     measures[i]=unmeasured;
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  switch (state) {
      case 0:
        is_button_pressed=digitalRead(push_button);
        if(is_button_pressed==HIGH){
          t=millis();
          state=1;
        }
        break;
      case 1:
        is_button_pressed=digitalRead(push_button);
        if(deltat()>=t_debounce && is_button_pressed==HIGH){
          t=millis();
          state=2;
        }else if(deltat()>=t_debounce && is_button_pressed==LOW){
          state=0;
        }
        break;
       case 2:
        is_button_pressed=digitalRead(push_button);
        if(is_button_pressed==LOW){
          state=3;
          Serial.println("Start measures");
          i=0;
        }
        break;
      case 3:
        digitalWrite(measuring_led,HIGH);
        is_button_pressed=digitalRead(push_button);
        if(deltat()>=(i+1)*10 && i<measures_len){
          measures[i]=analogRead(light_sensor);
          i++;
        }
        if(deltat()>=t_measuring || is_button_pressed==HIGH){
          state=4;
          Serial.println("Stop measures");
        }
        break;
      case 4:
        digitalWrite(measuring_led, LOW);
        Serial.println("Printing results");
        for(int i=0;i<measures_len;i++){
          if(measures[i]>0){
            if(measures[i]>maximum){
              maximum=measures[i];
            }else if(measures[i]<minimum){
              minimum=measures[i];
            }
            sum+=measures[i];
            n++;
          }else{
            break;
          }
        }
        Serial.print("max: ");
        Serial.println(maximum);
        Serial.print("min: ");
        Serial.println(minimum);
        Serial.print("mean: ");
        Serial.println((float)sum/(float)n);
        Serial.print("number of points: ");
        Serial.println(n);

        if(is_button_pressed==HIGH && deltat()>t_debounce){          
          state=5;
        }else if(is_button_pressed==LOW){
          state=6;
        }
        break;
      case 5:
        is_button_pressed=digitalRead(push_button);
        if(is_button_pressed==LOW){
          state=6;
        }
        break;
      case 6:
        for(int i=0;i<measures_len;i++){
          measures[i]=unmeasured;
        }
        minimum=5000;
        maximum=unmeasured;
        sum=0;
        n=0;
        state=0;
        break;
      default:
        Serial.println("reseting FSM");
        state=6;
  }

}

unsigned long deltat(){
  return millis()-t;
}


















