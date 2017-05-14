const unsigned int haupt_amp_rot=22;
const unsigned int haupt_amp_gel=24;
const unsigned int haupt_amp_grun=26;

const unsigned int neben_amp_rot=28;
const unsigned int neben_amp_gel=30;
const unsigned int neben_amp_grun=32;
const unsigned int bewegung_sensor=40;

unsigned int8_t state=1;
unsigned long t=0;

void grun_h();
void gelb_h();
void rot_h();
void rot_gelb_h();

void grun_n();
void gelb_n();
void rot_n();
void rot_gelb_n();


void setup() {
  // put your setup code here, to run once:
  pinMode(haupt_amp_grun, OUTPUT);
  pinMode(haupt_amp_gel, OUTPUT);
  pinMode(haupt_amp_rot, OUTPUT);

  pinMode(neben_amp_grun, OUTPUT);
  pinMode(neben_amp_gel, OUTPUT);
  pinMode(neben_amp_rot, OUTPUT);

  pinMode(bewegung_sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 switch (state){
     case 1:
       
       break;

     default:
       state=1;
       Serial.println("RESETING FSM");
 }
}

void grun_h(){
  digitalWrite(haupt_amp_rot, LOW);
  digitalWrite(haupt_amp_gel, LOW);
  digitalWrite(haupt_amp_grun, HIGH);
}
void gelb_h(){
  digitalWrite(haupt_amp_rot, LOW);
  digitalWrite(haupt_amp_gel, HIGH);
  digitalWrite(haupt_amp_grun, LOW);
}
void rot_h(){
  digitalWrite(haupt_amp_rot, HIGH);
  digitalWrite(haupt_amp_gel, LOW);
  digitalWrite(haupt_amp_grun, LOW);
}
void rot_gelb_h(){
  digitalWrite(haupt_amp_rot, HIGH);
  digitalWrite(haupt_amp_gel, HIGH);
  digitalWrite(haupt_amp_grun, LOW);
}

void grun_n(){
  digitalWrite(neben_amp_rot, LOW);
  digitalWrite(neben_amp_gel, LOW);
  digitalWrite(neben_amp_grun, HIGH);
}
void gelb_n(){
  digitalWrite(neben_amp_rot, LOW);
  digitalWrite(neben_amp_gel, HIGH);
  digitalWrite(neben_amp_grun, LOW);
}
void rot_n(){
  digitalWrite(neben_amp_rot, HIGH);
  digitalWrite(neben_amp_gel, LOW);
  digitalWrite(neben_amp_grun, LOW);
}
void rot_gelb_n(){
  digitalWrite(neben_amp_rot, HIGH);
  digitalWrite(neben_amp_gel, HIGH);
  digitalWrite(neben_amp_grun, LOW);
}




