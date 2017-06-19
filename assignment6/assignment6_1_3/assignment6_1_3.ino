/*
Der Durchschnitt des Arrays und der Median können unterschiedlich sein, da
sie unterschiedliche Herangehensweisen zur Bestimmung von Mittelwerten datellen.
Der Median beschreibt den Wert, der nach
den Messungen und sortierten Auflistung an der mittleren Stelle steht (wobei es
praktisch wäre eine ungerade Anzahl an Messungen zu haben, da dann eine Messung
immer an mittlerer Stelle steht).
Beim Durchschnittlichen Wert wird nicht das Ergebnis einer Messung genommen,
sondern das Ergebniss von allen Messungen betrachtet und durch die Anzahl an Messungen
geteilt.

*/



const int buzzer_pin=37;
const int trig_pin=35;
const int echo_pin=33;
const int button_pin=3;
const unsigned long t_debounce=100;

unsigned long sonar_timeout=90*1000;

unsigned long sample_time_ms=100;
unsigned long measure_time_ms=30000;
unsigned long t=0;

const int array_len=measure_time_ms/sample_time_ms;
unsigned long array_measures[30000/100];
unsigned int i=0;

unsigned int state=0;

int button_pressed=0;

unsigned long triggerAndFetchSonar();
unsigned long deltat();
void cleanArray();
float media(long unsigned int* a,int size);
float median(long unsigned int* a, int size);
void merge_sort(long unsigned int a[], long unsigned int b[], int size);
void partial_merge_sort(long unsigned int a[], long unsigned int b[],int begin, int end);
void merge(long unsigned int a[], long unsigned int b[], int begin, int mid, int end);
void copy(long unsigned int a[], long unsigned int b[], int begin, int end);


void setup() {
  // put your setup code here, to run once:
  pinMode(button_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
  cleanArray();
  t=millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(state);
  switch (state) {
      case 0:
        // do something
        button_pressed=digitalRead(button_pin);
        if(button_pressed==HIGH){
          state=1;
          t=millis();
        }
        break;
      case 1:
        // do something
        button_pressed=digitalRead(button_pin);
        if(button_pressed==LOW && deltat()>=t_debounce){
          state=2;
          t=millis();
          i=0;
        }

        break;
      case 2:
        if(deltat()>=(i+1)*sample_time_ms){
          state=3;
        }
        break;
      case 3:
        array_measures[i++]=triggerAndFetchSonar();
       
        if(i==array_len){
          state=5;
        }else if(digitalRead(button_pin)==HIGH){
          state=4;
          t=millis();
        }else{
          state=2;
        }
        break;
      case 4:
        button_pressed=digitalRead(buzzer_pin);
        if(button_pressed==LOW && deltat()>=t_debounce){
          state=5;
        }
        break;
      case 5:
        Serial.print("Median: ");
        Serial.println(median(array_measures,i));
        Serial.print("Media: ");
        Serial.println(media(array_measures,i));
        cleanArray();
        state=0;
        //while(true);
        break;

      default:
        // do something
        state=0;
        Serial.println("RESETING FSM");
  }
}


unsigned long triggerAndFetchSonar () {
  digitalWrite ( trig_pin , LOW ) ;
  delayMicroseconds (2) ;
  digitalWrite ( trig_pin , HIGH ) ;
  delayMicroseconds (10) ;
  digitalWrite ( trig_pin , LOW ) ;
  return pulseIn ( echo_pin , HIGH , sonar_timeout ) ;
}

unsigned long deltat(){
  return(millis()-t);
}

void cleanArray(){
  for (int j=0;j<array_len;j++){
    array_measures[j]=-1;
  }
}

float media(long unsigned int* a,int size){
  float sum=0;
  for(int i=0;i<size;i++){
    sum+=a[i];
  }
  return sum/i;
}

float median(long unsigned int* a, int size){
  long unsigned int b[size];
  merge_sort(a,b,size);
  if(size%2!=0){
    return a[size/2];
  }else{
    return (a[size/2]+a[size/2-1])/2.0;
  }
}

void merge_sort(long unsigned int a[], long unsigned int b[], int size)
{
 partial_merge_sort(a, b, 0, size);
}
void partial_merge_sort(long unsigned int a[], long unsigned int b[],int begin, int end)
{
 if (end - begin < 2)
 return;

 // Split and sort
 int mid = begin + (end - begin) / 2;
 partial_merge_sort(a, b, begin, mid);
 partial_merge_sort(a, b, mid, end);

 // Merge and copy
 merge(a, b, begin, mid, end);
 copy(a, b, begin, end);
}

void merge(long unsigned int a[], long unsigned int b[], int begin, int mid, int end) {
 int i_begin = begin;
 int i_mid = mid;
 for (int j = begin; j < end; j++){
   if (i_begin < mid && (i_mid >= end || a[i_begin] <= a[i_mid]))
    b[j] = a[i_begin++];
   else
    b[j] = a[i_mid++];
 }  
}

void copy(long unsigned int a[], long unsigned int b[], int begin, int end) {
 for (int k = begin; k < end; k++)
 a[k] = b[k];
} 












