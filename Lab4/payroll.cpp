#include "payroll.h"
#include <iostream>
using namespace std;

PayRoll::PayRoll(){
}

PayRoll::PayRoll(string n,double pay ,double h){
	name = n;
	payRate = pay;
	hours = h;
}

double PayRoll::getTotal(){
	return payRate * hours;

	}

double PayRoll::getRate(){
	return payRate;

}

double PayRoll::getHours(){
	return hours;

}

string PayRoll::getName(){
	return name;
}

void PayRoll::setRate(double pay){
	payRate = pay;

}

void PayRoll::setName(string n){
	name = n;
}

void PayRoll::setHours(double h){
	hours = h;
}
/*
void PayRoll::empInfo(){
	cout << "Name: " << getName() << endl;
	cout << "Pay rate: " << getRate() << endl;
	cout << "Total Hours :" << getHours();
	cout << "Total Pay : $" << getTotal();
	cout << "--------------------------------\n";
}
*/
