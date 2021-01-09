#ifndef PAYROLL_H
#define PAYROLL_H
#include <iostream>
using namespace std;

class PayRoll{
	private:
		string name;
		double payRate;
		double hours;
	public:
		PayRoll();
		PayRoll(string,double,double);
		double getTotal();
		double getRate();
		double getHours();
		string getName();
		void setRate(double);
		void setName(string);
		void setHours(double);
		void empInfo();

};

#endif
