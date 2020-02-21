/* Robert Davis 
 * Computer scinece 120
 * Lab 1 Bonus 
 */
#include <iostream>
#include <iomanip>
using namespace std;
double mean(int arr[],int size);
double mean2(int *arr,int size);

int main(){
	
	
	double meanf1 = 0;
	double meanf2 = 0;
	
	int *dynamicArray;
	
	int size = 10;
	// makes an array of beginning size 10
	dynamicArray = new int[size];
	cout << "Begin typing nuumbers (Enter -99 if you would like to stop typing numbers)  : \n";
	
	for(int i = 0;i < size;i++){
	/* This if statement 
 * 	makes sure that the array size increases whenever i 
 * 	is getting close to size.
 * 	I did this so that you can enter
 * 	as many integers as you 
 * 	want.
 */
 		
		if(i == (size - 1)){
			size += 10;
			// Reallocate memory to the new size
			int* temp = new int [size];
			
			// Takes data from old array and 
			// puts it into the new one
			for(int k = 0; k < i; k++)
				temp[k] = dynamicArray[k];
			// This deletes the old array 
			delete [] dynamicArray;
			dynamicArray = temp;
			
		}
		cin >> dynamicArray[i];		
		if(dynamicArray[i] == -99){
		size = i;
		}
	}
	
	meanf1 = mean(dynamicArray,size);
	meanf2 = mean2(dynamicArray,size);
	
	cout << "The mean of the array using function 1 is " << meanf1 << endl;
	cout << "The mean of the array using function 2 is " << meanf2 << endl;
	
	delete [] dynamicArray;
	
	return 0;
}


double mean(int arr[],int size){
	
	double sum = 0;
	double mean = 0;
	
	for(int i = 0;i < size;i++){
		sum += arr[i];
	
	}
	
	mean = double((sum)/(size));

	return mean;	
}
double mean2(int *arr,int size){
	
	double sum = 0;
	double mean2 = 0;
		
	for(int i = 0;i < size ;i++){
		
		sum += *(arr + i);

	}
	cout << sum <<  " / " << size << endl; 	
	mean2 = double(sum /(size));
	return mean2;
}

