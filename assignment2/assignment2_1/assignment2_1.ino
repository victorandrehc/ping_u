const int haupt_amp_rot=22;
const int haupt_amp_gel=24;
const int haupt_amp_grun=26;
const int t_ms=1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(haupt_amp_grun, OUTPUT);
  pinMode(haupt_amp_gel, OUTPUT);
  pinMode(haupt_amp_rot, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //1st state rot
  digitalWrite(haupt_amp_rot, HIGH);
  digitalWrite(haupt_amp_grun, LOW);
  digitalWrite(haupt_amp_gel, LOW);
  delay(t_ms);
  //2nd state rot-gelb
  digitalWrite(haupt_amp_rot, HIGH);
  digitalWrite(haupt_amp_grun, LOW);
  digitalWrite(haupt_amp_gel, HIGH);
  delay(t_ms);
  //3rd state grun
  digitalWrite(haupt_amp_rot, LOW);
  digitalWrite(haupt_amp_grun, HIGH);
  digitalWrite(haupt_amp_gel, LOW);
  delay(t_ms);
  //4th state gelb
  digitalWrite(haupt_amp_rot, LOW);
  digitalWrite(haupt_amp_grun, LOW);
  digitalWrite(haupt_amp_gel, HIGH);
  delay(t_ms);

}





