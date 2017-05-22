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
int runde=1;
int counter=0;
int countersequence=0;
int state = 0;

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
		t = millis();
		if (digitalRead(buttonblau)== HIGH)
		{
		 if (delta()>=50 && digitalRead(buttonblau) == LOW)
		 {
		 	Serial.println("Blau gepushed!");
		 	speicher[counter] = 1;
		 	t = millis();
			state = 1;
		 }
		}else if (digitalRead(buttonrot) == HIGH)
		{
		 if (delta()>=50 && digitalRead(buttonrot) == LOW)
		 {
		 	Serial.println("Rot gepushed!");
		 	speicher[counter] = 2;
			t = millis();
			state = 2;
		 }
		}else if (digitalRead(buttongruen) == HIGH)
		{	
		 if (delta()>=50 && digitalRead(buttongruen) == LOW)
		 {
		 	Serial.println("Gruen gepushed!");
		 	speicher[counter] = 3;
			t = millis();
			state = 3;
		 }
		}else if (digitalRead(buttongelb) == HIGH)
		{
		 if (delta()>=50 && digitalRead(buttongelb) == LOW)
		 {
		 	Serial.println("Gelb gepushed!");
		 	speicher[counter] = 4;
			t = millis();
			state= 4;
		 }
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
		 	state = 0;
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
		 	state = 0;
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
		 	state = 0;
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
		 	state = 0;
		 }
		break;
		default:
		break;
	}
	counter++;
	if (counter >99){
		while(1){
			Serial.println("Speicherueberlauf!");
			delay(500);
		}
	}
	while(countersequence < runde && counter < 100){
		switch(speicher[counter]){
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
	}
	countersequence = 0;
	runde++;
	state = 0;
}

unsigned long delta(){
	return millis()-t;
}