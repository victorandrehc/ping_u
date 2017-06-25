

int a[7],b[7];
int size=6;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("raw ");
  for(int i=0;i<size;i++){
    a[i]=size-i;
    Serial.print(a[i]);
    Serial.print(" ");
  }
  Serial.println("");
   Serial.println("Median: ");
  Serial.println(median(a,size));
  merge_sort(a,b,size);
  Serial.println("sorted");
  for(int i=0;i<size;i++){
    Serial.print(a[i]);
    Serial.print(" ");
  }
  Serial.println("");
 

}

void loop() {
  // put your main code here, to run repeatedly:

}

float median(int* a, int size){
  int b[size];
  merge_sort(a,b,size);
  if(size%2!=0){
    return a[size/2];
  }else{
    Serial.println(a[size/2]);
    Serial.println(a[size/2]-1);
    return (a[size/2]+a[size/2-1])/2.0;
  }
}

void merge_sort(int a[], int b[], int size)
{
 partial_merge_sort(a, b, 0, size);
}
void partial_merge_sort(int a[], int b[],int begin, int end)
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

void merge(int a[], int b[], int begin, int mid, int end) {
 int i_begin = begin;
 int i_mid = mid;
 for (int j = begin; j < end; j++){
   if (i_begin < mid && (i_mid >= end || a[i_begin] <= a[i_mid]))
    b[j] = a[i_begin++];
   else
    b[j] = a[i_mid++];
 }  
}

void copy(int a[], int b[], int begin, int end) {
 for (int k = begin; k < end; k++)
 a[k] = b[k];
} 












