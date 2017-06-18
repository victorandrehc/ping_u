const int buzzer_pin=37;

float seno;
int frequencia;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   for(int x=0;x<180;x++){
  //converte graus para radiando e depois obtém o valor do seno
  seno=(sin(x*3.1416/180));
  //gera uma frequência a partir do valor do seno
  frequencia = 2000+(int(seno*1000));
  tone(buzzer_pin,frequencia);
  delay(2);
 }
}


