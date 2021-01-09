#include <iostream>
#include <time.h>
#include <chrono>

using namespace std;
// Swap function
void swap(int& A, int& B){
  int temp = A;
  A = B;
  B = temp;
}
// Function that takes takes the start and end values in an array.
int partition(int array[], int start, int end){

  int piv = array[start];
  int i = start + 1;

  for(int j = start + 1;j <= end;j++){
    if(array[j] < piv){
      swap(array[i],array[j]);
      i++;
    }
  }
  swap(array[start],array[i-1]);
  return i -1;
}

void quickSort(int array[],int start, int end){
  int piv;
  if(start <= end - 1){
    piv = partition(array,start,end);
    quickSort(array,start,piv-1);
    quickSort(array,piv+1,end);
  }
}

void print(int array[],int size){
  for(int i = 0;i < size;i++){
    cout << array[i] << " ";

  }
  cout << endl;

}

int *randArray(int size){
  srand(time(NULL));

  int *num = new int[size];
  for(int i = 0;i < size;i++){
    num[i] = rand()%9+1;
  }
  return num;
}


int main(){
  int num1 = 12;
  int num2 = 8;

  cout <<"First Number: " << num1 << "  Second Number: " << num2 << endl;
  cout <<"----Swap Test----" << endl;

  swap(num1,num2);
  cout <<"First Number Swapped: " << num1 << endl;
  cout <<"Second Number Swapped: " << num2 << endl;

  cout << endl;
  int array1[] = {5,10};
  cout <<"First Number: " << 5 << "  Second Number: " << 10 << endl;
  cout <<"----Swap Test for arrays---";
  cout << endl;

  swap(array1[0],array1[1]);
  cout <<"First number: " << array1[0] << "  Second Number: " << array1[1] << endl;
  cout << endl;

  int array2[] = {3,1,9,4,9,2};
  print(array2,4);
  cout <<"----Partition Testing----" << endl;
  int temp = partition(array2,0,5);
  cout <<"Pivoted at: " << temp << endl;
  cout <<"Value at pivot: " << array2[temp] << endl;

  print(array2,5);
  cout << "----Array in order----" << endl;
  int array3[]{1,2,3,4,5,6,7,8,9,10};
  print(array3,10);

  //auto start = std::chrono::system_clock::now();
  quickSort(array3,0,9);
/*
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout << "finished at " << std::ctime(&end_time)
  << "elapsed time: " << elapsed_seconds.count() << "s\n";
*/
  print(array3,10);

  cout << endl;

  cout << "----Array backwards----" << endl;
  int array4[] = {10,9,8,7,6,5,4,3,2,1};
  print(array4,10);

  start = std::chrono::system_clock::now();
  quickSort(array4,0,9);

  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout << "finished at " << std::ctime(&end_time)
  << "elapsed time: " << elapsed_seconds.count() << "s\n";

  print(array4,10);


  cout << "----Random Array of 50 elements----" << endl;

  int length = 50;

  int *array5 = randArray(length);

  print(array5,length);

  start = std::chrono::system_clock::now();
  quickSort(array5,0,length - 1);

  auto end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout << "finished at " << std::ctime(&end_time)
  << "elapsed time: " << elapsed_seconds.count() << "s\n";

cout << endl;
print(array5,length);
int length2 = 100;
cout <<"----Random Array of 100 elements----" << endl;
int *array6 = randArray(length2);
print(array6,100);
cout << endl;
start = std::chrono::system_clock::now();
quickSort(array6,0,length2 - 1);

auto end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
 end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "finished at " << std::ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n";

print(array6,100);

delete array6[];


return 0;

}
