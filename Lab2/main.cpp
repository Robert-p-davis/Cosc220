#include"payroll.h"
#include <iostream>
using namespace std;
/* Robert Davis
 * Cosc 120
 * Lab2
 */
int main(){
	PayRoll people[7];
	PayRoll *ptr[7];
	double hours = 0;
	
	people[0] =  PayRoll("Steve",17.3);
	people[1] = PayRoll("Bevan",3);
	people[2] = PayRoll("Jack",100);
	people[3] = PayRoll("Maynard",12.30);
	people[4] = PayRoll("Gary",11.11);
	people[5] = PayRoll("Daryl",44);
	people[6] = PayRoll("Anderson",19.55);
	
	
	for(int k = 0;k < 7;k++){
	ptr[k] = &people[k];
}
	for(int i = 0;i < 7;i++){
		cout << "Enter the hours for " <<  ptr[i]->getName()  << ". :  ";
	
		cin >> hours;
		while(hours < 0 || hours > 60){
			cout << " Minimum hours is 0. Maximum hours is 60. Enter hours again.\n";
			cin >> hours;
		}
	

	ptr[i]->setHours(hours);
	ptr[i]->getPay();
	ptr[i]->print();	
	}
//Size of the regular array is 168 bytes 
cout <<"Size of regular array " <<  sizeof(people) << endl;





//Size of the pointer array is 56 bytes
cout <<"Size of pointer array "  <<  sizeof(ptr) << endl;

cout << "Address of both arrays " << endl;
for(int i = 0;i < 7;i++){
	cout << "Regular \t pointer " << endl;
	cout << &people[i] << "\t" << &ptr[i] << endl;
}


/* In conclusion the pointer array was 112 bytes less 
 * then the regular array
 * The pointer array is less then the regular array 
 * because it only points to one element.
 * The regular array holds the memory of everything at once.
 *
 * The memory locations seem to be increasing every time it moves or points to the next object.
 * But the pointer array uses less memory then the regular one.
 */


	
	

return 0;
}


