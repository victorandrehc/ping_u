const int SIZE=6;

int input_1[SIZE],input_2[SIZE],output[SIZE];


int add(int* output,int* input_1,int* input_2,int size);
void print_array(int* arr,int size);

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<SIZE;i++){
    input_1[i]=0;
    input_2[i]=0;
    output[i]=0;
  }
  input_1[3]=1;
  input_1[4]=1;
  input_1[5]=1;

  input_2[4]=1;
  input_2[5]=1;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  add(output,input_1,input_2,SIZE);
  print_array(output,SIZE);
  delay(500);
}

int add(int* output,int* input_1,int* input_2,int size){
  int aux=0;
  for(int i=size-1;i>0;i--){
    output[i]=(input_1[i]+input_2[i]+aux)%2;//(input_1[i] XOR input_2[i]) XOR aux;
    aux=(input_1[i] && input_2[i]) || (aux and(input_1[i]+input_2[i]%2));
  }
  return aux;
}

void print_array(int* arr,int size){
  for(int i=0;i<size;i++){
    Serial.print(arr[i]);
    Serial.print(", ");
  }
  Serial.println("");
}




