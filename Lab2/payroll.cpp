#include"payroll.h"
#include <iostream>
using namespace std;

// Robert Davis
// Computer Science 220
// Lab2
	PayRoll :: PayRoll (){
	}

//Function sets the employees name
PayRoll:: PayRoll(string empName,double p){
	payRate = p;
	name = empName;
}

// Function that computers the pay of employee
double PayRoll::getPay(){
	return payRate * hours;
}

//Function sets hours that employee worked
void PayRoll:: setHours(double h){
	hours = h;
}
//Function sets the payrate of the employee

void PayRoll:: print(){
	cout << name << " makes $" << payRate << " and hour and works for " << hours << " hours.\n";
	cout << name << "(s) total pay roll is $" << getPay() <<"\n";
	
}

string PayRoll :: getName(){
	return name;
}

