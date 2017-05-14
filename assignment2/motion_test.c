const int haupt_amp_rot=22;
const int haupt_amp_gel=24;
const int haupt_amp_grun=26;

const int neben_amp_rot=28;
const int neben_amp_gel=30;
const int neben_amp_grun=32;
const int bewegung_sensor=40;

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
 int a=digitalRead(bewegung_sensor);
 digitalWrite(neben_amp_grun, a);
 Serial.println(a);
}
