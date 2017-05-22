int buttonblau=4; // taster 1
int buttonrot=5; // taster 2
int buttongruen=6; //taster 3
int buttongelb=7; //taster 4

int ledblau=8;
int ledrot=9;
int ledgruen=10;
int ledgelb=11;

int lautsprecher=3;

unsigned long t=0;
int abspielenUser=750;
int abspielenArduino=500;
int breaktime=100;

int speicher[100] = {0};
int counter=0;
int countersequence=0;
int state = 0;
int led = 0;

int blaupushed=0;
int rotpushed=0;
int gruenpushed=0;
int gelbpushed=0;

unsigned long delta();
void initial();

void setup(){
	pinMode(buttonblau, INPUT);
	pinMode(buttonrot, INPUT);
	pinMode(buttongruen, INPUT);
	pinMode(buttongelb, INPUT);

	pinMode(ledgruen, OUTPUT);
	pinMode(ledgelb, OUTPUT);
	pinMode(ledblau, OUTPUT);
	pinMode(ledrot, OUTPUT);
	pinMode(lautsprecher, OUTPUT);

	Serial.begin(9600);
}

void loop(){
  switch(state){
     case 0:
       //Take input
       if(digitalRead(buttonblau)==HIGH){
         Serial.println("Blau gepushed!");
         speicher[counter] = 1;
         state = 1;
         led = 1;
       }else if (digitalRead(buttonrot)==HIGH){
         Serial.println("Rot gepushed!");
         speicher[counter] = 2;
         state = 1;
         led = 2;
       }else if (digitalRead(buttongruen)==HIGH){
         Serial.println("Gruen gepushed!");
         speicher[counter] = 3;
         state = 1;
         led = 3;
       }else if (digitalRead(buttongelb)==HIGH){
         Serial.println("Rot gepushed!");
         speicher[counter] = 4;
         state = 1; 
         led = 4;
       }
       break;
     case 1:
       //Repeat input
       t = millis();
       switch(led){
          case 1:
            digitalWrite(ledblau, HIGH);
            tone(lautsprecher,220);
            break;
          case 2:
            digitalWrite(ledrot,HIGH);
            tone(lautsprecher,440);
            break;
          case 3:
            digitalWrite(ledgruen,HIGH);
            tone(lautsprecher,660);
            break;
          case 4:
            digitalWrite(ledgelb,HIGH);
            tone(lautsprecher,880);
            break;
       }
       state = 2;
       break;
     case 2:
       //Stop repeating input
       if(delta()>=abspielenUser){
          switch(led){
            case 1:
              digitalWrite(ledblau, LOW);
              break;
            case 2:
              digitalWrite(ledrot,LOW);
              break;
            case 3:
              digitalWrite(ledgruen,LOW);
              break;
            case 4:
              digitalWrite(ledgelb,LOW);
              break;
         }
         noTone(lautsprecher);
         state = 3;
         counter++;
         t=millis();
       }
       break;
     case 3:
       //break
       if(delta() >= breaktime){
         state=4;
       }  
       break;
     case 4:
       //Start repeating sequence
       led = speicher[countersequence];
       countersequence++;   
       t = millis();
       switch(led){
          case 1:
            digitalWrite(ledblau, HIGH);
            tone(lautsprecher,220);
            break;
          case 2:
            digitalWrite(ledrot,HIGH);
            tone(lautsprecher,440);
            break;
          case 3:
            digitalWrite(ledgruen,HIGH);
            tone(lautsprecher,660);
            break;
          case 4:
            digitalWrite(ledgelb,HIGH);
            tone(lautsprecher,880);
            break;
       }
       state = 5;
       break;
     case 5:
       if(delta()>=abspielenArduino){
          switch(led){
            case 1:
              digitalWrite(ledblau, LOW);
              break;
            case 2:
              digitalWrite(ledrot,LOW);
              break;
            case 3:
              digitalWrite(ledgruen,LOW);
              break;
            case 4:
              digitalWrite(ledgelb,LOW);
              break;
         }
         noTone(lautsprecher);
         t=millis();
         state=6;
      }
      break;
    case 6:
      //Break or end of sequence
      if(delta()>= breaktime){
        if(countersequence == counter){
           countersequence=0;
           state=0;
         }else{
            state=4;
         }
      }
      break;    
  }
}
       
      
         

unsigned long delta(){
	return millis()-t;
}
