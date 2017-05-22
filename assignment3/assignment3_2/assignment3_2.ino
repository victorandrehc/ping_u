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
       else if (digitalRead(buttongelb)==HIGH){
         Serial.println("Rot gepushed!");
         speicher[counter] = 4;
         state = 1; 
         led = 4;
       }
       break;
     case 1:
       t = millis();
  
  	switch(state){
		case 0:
		t = millis();
		if (digitalRead(buttonblau)== HIGH)
		{
		 	Serial.println("Blau gepushed!");
		 	speicher[counter] = 1;
		 	t = millis();
			state = 1;
		}else if (digitalRead(buttonrot) == HIGH)
		{
		 	Serial.println("Rot gepushed!");
		 	speicher[counter] = 2;
			t = millis();
			state = 2;
		}else if (digitalRead(buttongruen) == HIGH)
		{	
		
		 	Serial.println("Gruen gepushed!");
		 	speicher[counter] = 3;
			t = millis();
			state = 3;
		 
		}else if (digitalRead(buttongelb) == HIGH)
		{
	
		 	Serial.println("Gelb gepushed!");
		 	speicher[counter] = 4;
			t = millis();
			state= 4;

		}
		break;
		case 1:
		 if (delta()<abspielenUser)
		 {
		 	digitalWrite(ledblau, HIGH);
		 	tone(lautsprecher, 220);
		 }else{
		 	digitalWrite(ledblau, LOW);
		 	noTone(lautsprecher);
		 	state = 5;
		 }
		break;
		case 2:
		if (delta()<abspielenUser)
		 {
		 	digitalWrite(ledrot, HIGH);
		 	tone(lautsprecher, 440);
		 }else{
		 	digitalWrite(ledrot, LOW);
		 	noTone(lautsprecher);
		 	state = 5;
		 }
		break;
		case 3:
		 if (delta()<abspielenUser)
		 {
		 	digitalWrite(ledgruen, HIGH);
		 	tone(lautsprecher, 660);
		 }else{
		 	digitalWrite(ledgruen, LOW);
		 	noTone(lautsprecher);
		 	state = 5;
		 }
		break;
		case 4:
		 if (delta()<abspielenUser)
		 {
		 	digitalWrite(ledgelb, HIGH);
		 	tone(lautsprecher, 880);
		 }else{
		 	digitalWrite(ledgelb, LOW);
		 	noTone(lautsprecher);
		 	state = 5;
		 }
		break;
		default:
		break;
	}
        if(state == 5){
         counter++;
	if (counter >99){
		while(1){
			Serial.println("Speicherueberlauf!");
			delay(500);
		}
	}
	while(countersequence < counter && counter < 100){
		switch(speicher[countersequence]){
			case 0:
				state = 0;
			break;
			case 1:
				 if (delta()<abspielenArduino)
				 {
		 			digitalWrite(ledblau, HIGH);
		 			tone(lautsprecher, 220);
				 }else{
				 	digitalWrite(ledblau, LOW);
				 	noTone(lautsprecher);
				 }
			break;
			case 2:
			 	 if (delta()<abspielenArduino)
				 {
		 			digitalWrite(ledrot, HIGH);
		 			tone(lautsprecher, 440);
				 }else{
				 	digitalWrite(ledrot, LOW);
				 	noTone(lautsprecher);
				 }
			break;
			case 3:
				 if (delta()<abspielenArduino)
				 {
		 			digitalWrite(ledgruen, HIGH);
		 			tone(lautsprecher, 660);
				 }else{
				 	digitalWrite(ledgruen, LOW);
				 	noTone(lautsprecher);
				 }
			break;
			case 4:
				 if (delta()<abspielenArduino)
				 {
		 			digitalWrite(ledgelb, HIGH);
		 			tone(lautsprecher, 880);
				 }else{
				 	digitalWrite(ledgelb, LOW);
				 	noTone(lautsprecher);
				 }
			break;
                        
		}
                countersequence++;
	}
	countersequence = 0;
	state = 0;
        }
}

unsigned long delta(){
	return millis()-t;
}
