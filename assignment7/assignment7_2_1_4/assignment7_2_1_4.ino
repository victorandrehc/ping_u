struct list_node {
  unsigned long time;
  int light;
  int temp;
  struct list_node *next; 
};

struct list_node *head = NULL;
unsigned long time = 0;
int pin_light = A3;
int pin_temp = A8;
int count = 0;

void setup(){

}

void loop(){
  if(delta_t() >= 1000){
     time = millis();
     
     struct list_node *n;
     n = (struct list_node *) malloc(sizeof(struct list_node));
     n->time=millis();
     
     int reading = analogRead(pin_light);
     n->light=map(reading, 0, 410, -50, 150);
     
     reading=analogRead(pin_temp);
     n->temp=map(reading, 0, 1023, 0, 100);
     
     n->next = head;
     head=n;
   }
}

unsigned long delta_t(){
  unsigned long ret = millis()-time;
  return ret;
}

