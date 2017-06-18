const int buzzer_pin=37;
const int trig_pin=35;
const int echo_pin=33;

unsigned long timeout_min=150,timeout_max=1000;
unsigned long freq_min=1, freq_max=4000;
unsigned long sonar_timeout=1000;

float x=0;

unsigned long triggerAndFetchSonar();


void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer_pin, OUTPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long t=triggerAndFetchSonar();
  if(t<timeout_min){
    t=timeout_min;
  }else if(t>timeout_max){
    t=timeout_max;
  }
  int f=map(t,timeout_min,timeout_max,freq_min,freq_max);
  x=(4.0*x+f)/5.0;

  tone(buzzer_pin,x);
  Serial.println(t);
  Serial.println(f);
  Serial.println(x);
  Serial.println("----");
  delay(100);
}

unsigned long triggerAndFetchSonar () {
  digitalWrite ( trig_pin , LOW ) ;
  delayMicroseconds (2) ;
  digitalWrite ( trig_pin , HIGH ) ;
  delayMicroseconds (10) ;
  digitalWrite ( trig_pin , LOW ) ;
  return pulseIn ( echo_pin , HIGH , sonar_timeout ) ;
}


  



