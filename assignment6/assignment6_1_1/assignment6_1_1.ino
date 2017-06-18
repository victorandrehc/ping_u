const int buzzer_pin=37;
const int trig_pin=35;
const int echo_pin=33;
const int button_pin=3;

unsigned long sonarTimeout=10000;

unsigned long triggerAndFetchSonar();


void setup() {
  // put your setup code here, to run once:
  pinMode(button_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(triggerAndFetchSonar());
  delay(500);
}


unsigned long triggerAndFetchSonar () {
  digitalWrite ( trig_pin , LOW ) ;
  delayMicroseconds (2) ;
  digitalWrite ( trig_pin , HIGH ) ;
  delayMicroseconds (10) ;
  digitalWrite ( trig_pin , LOW ) ;
  return pulseIn ( echo_pin , HIGH , sonarTimeout ) ;
}





