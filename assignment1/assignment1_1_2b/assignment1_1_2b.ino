const unsigned int led = 13;
const unsigned int t_on=3000, t_off=1000;

void setup () {
  pinMode ( led , OUTPUT );
}
void loop () {
  digitalWrite ( led , HIGH );
  delay (t_on);
  digitalWrite ( led , LOW ) ;
  delay(t_off);
}
