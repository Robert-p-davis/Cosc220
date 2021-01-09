
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;

void swap(int &x, int &y);



bool isSorted(int *A, int size);

 int Bubblesort(int *B, int size);

int selection(int *C, int size);

int insertion(int *D, int size);

int *randArray(int size);

void backwards(int *F,int size);

int counter = 0;

int main(){
  srand(time(NULL));
  int lengthSize = 6;
  int nums[] = {10,100,500,1000,2000,};
  int *array;

  for(int i = 0;i < lengthSize;i++){
    for(int j = 0;j < 3;j++){
      array = randArray(nums[i]);
      if(j == 0){
        insertion(array,nums[i]);
        cout <<"Array is in ascending order.\n";

      }else if(j == 1){
        backwards(array,nums[i]);
        cout <<"Array is in descending order.\n";
      }else if ( j == 2){
        cout <<"Array is in random order\n";

      }
      auto start = chrono::system_clock::now();

      Bubblesort(array,nums[i]);

      auto end = chrono::system_clock::now();
      chrono::duration<double> elapsed_seconds = end - start;
      time_t end_time = chrono::system_clock::to_time_t(end);
      if(isSorted(array,nums[i])){
        cout <<"Bubblesort was used on : " << nums[i] << " numbers. " << endl;
        cout <<"Finished at " << ctime(&end_time) << " elpased time " << elapsed_seconds.count() << endl;
        cout << "Total swaps : " << counter << endl;

      }
      counter = 0;
      delete []array;
    }
    cout << endl << endl;
  }
  for(int i = 0;i < lengthSize;i++){
    for(int j = 0;j < 3;j++){
      array = randArray(nums[i]);
      if(j == 0){
        insertion(array,nums[i]);
        cout <<"Array is in ascending order.\n";

      }else if(j == 1){
        backwards(array,nums[i]);
        cout <<"Array is in descending order.\n";
      }else if ( j == 2){
        cout <<"Array is in random order\n";

      }
      auto start = chrono::system_clock::now();

      insertion(array,nums[i]);

      auto end = chrono::system_clock::now();
      chrono::duration<double> elapsed_seconds = end - start;
      time_t end_time = chrono::system_clock::to_time_t(end);
      if(isSorted(array,nums[i])){
        cout <<"Insertion sort  was used on : " << nums[i] << " numbers. " << endl;
        cout <<"Finished at " << ctime(&end_time) << " elpased time " << elapsed_seconds.count() << endl;
        cout << "Total swaps : " << counter << endl;

      }
      counter = 0;
      delete []array;
    }
    cout << endl << endl;
  }
  for(int i = 0;i < lengthSize;i++){
    for(int j = 0;j < 3;j++){
      array = randArray(nums[i]);
      if(j == 0){
        insertion(array,nums[i]);
        cout <<"Array is in ascending order.\n";

      }else if(j == 1){
        backwards(array,nums[i]);
        cout <<"Array is in descending order.\n";
      }else if ( j == 2){
        cout <<"Array is in random order\n";

      }
      auto start = chrono::system_clock::now();

      selection(array,nums[i]);

      auto end = std::chrono::system_clock::now();
      chrono::duration<double> elapsed_seconds = end-start;
      time_t end_time = chrono::system_clock::to_time_t(end);
      cout << "Finished at " << ctime(&end_time)
      << "elapsed time: " << elapsed_seconds.count() << "s\n";
      if(isSorted(array,nums[i])){
        cout <<"Selection sort  was used on : " << nums[i] << " numbers. " << endl;
        cout <<"Finished at " << ctime(&end_time) << " elpased time " << elapsed_seconds.count() << endl;
        cout << "Total swaps : " << counter << endl;

      }
      counter = 0;
      delete []array;
    }
    cout << endl << endl;
  }



  return 0;
}

//Functions


void swap( int &x, int &y){
  int temp;
  temp = x;
  x = y;
  y = temp;
  counter++;

}

bool isSorted(int *arr,int size){
  for(int i = 1;i < size;i++){
      if(arr[i-1] > arr[i]){
        return false;
      }
  }
  return true;
}

void backwards(int *F,int size){
  int temp;
  for(int i = 0;i < size;i++){
    temp = i;
  }while(temp > 0 && (F[temp]>F[temp - 1])){
    swap(F[temp],F[temp - 1]);
    temp--;
  }
}
int *randArray(int size){
  int *temp = new int[size];
  for(int i = 0;i < size;i++){
    temp[i] = rand()%100 + 1;
  }
  return temp;
}


int Bubblesort(int *A, int size){
  counter = 0;
bool swapped = true;
  while(swapped){
    swapped = false;
    for(int i = 0; i < size - 1;i++){
      if(A[i] > A[i+1]){
        swap(A[i],A[i+1]);
        swapped = true;
      }
    }
  }
  return counter;
}

int selection(int *B, int size){
  counter = 0;
  for(int i = 0; i < size - 2;i++){
  int min = i;
    for(int j = i+ 1; j < size-1;j++){
      if(B[j] < B[min]){
        min = j;
      }
    }
    swap(B[i],B[min]);
  }
  return counter;
}

int insertion(int *C, int size){
  counter = 0;
  int j;
  for(int i = 1;i < size;i++){
    j = i;
    while(j > 0 &&(C[j] < C[j-1])){
      swap(C[j],C[j-1]);
      j--;
    }


  }
  return counter;
}
