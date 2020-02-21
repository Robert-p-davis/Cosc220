#ifndef PAYROLL_H
#define PAYROLL_H
#include <iostream>
using namespace std;
class PayRoll{
// your class prototype here 
	private:
		string name;
		double payRate;
		double hours;	
	public:
	PayRoll();
	PayRoll(string, double);	
	double getPay();
	void setHours(double);
	string getName();
	void print();
	
	
};

#endif

