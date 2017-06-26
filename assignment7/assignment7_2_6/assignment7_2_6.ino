struct list_node {
  unsigned long time;
  int light;
  int temp;
  struct list_node *next; 
  struct list_node *previous;
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
     if(count==100){
      remove_last();
      count=count-1;
     }
     
     time = millis();
     
     struct list_node *n;
     n = (struct list_node *) malloc(sizeof(struct list_node));
     n->time=millis();
     
     int reading = analogRead(pin_light);
     n->light=map(reading, 0, 410, -50, 150);
     
     reading=analogRead(pin_temp);
     n->temp=map(reading, 0, 1023, 0, 100);
     
     if(head == NULL){
       n->next=n;
       n->previous=n;
       head=n;
     }else{
       n->next=head;
       head->previous->next=n;
       n->previous=head->previous;
       head->previous=n;
       head=n;
     }  
     count=count+1;
   }
}

void remove_last(){
  struct list_node *n;
  n = (struct list_node *) malloc(sizeof(struct list_node));
  struct list_node *m;
  m = (struct list_node *) malloc(sizeof(struct list_node));
  
  n = head->previous;
  m = n->previous;
  
  head->previous=m;
  m->next=head;
  free(n);
  
}
unsigned long delta_t(){
  unsigned long ret = millis()-time;
  return ret;
}

