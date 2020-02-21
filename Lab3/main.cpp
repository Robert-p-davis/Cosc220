#include <iostream>
#include <fstream>
#include "Listpayroll.h"
using namespace std;

int main(){
	PayRollList  ppl;
	/*
	ppl.insert("Rodger",12.8,22);
	ppl.insert("Lawrence",20,36);
	ppl.insert("Bob",9.99,23);
	ppl.insert("Jack",7.98,17);
	ppl.insert("Kieth",30,5);
	ppl.printPayChecks();
	*/

	ifstream infile;
	ofstream outfile;
	infile.open("employee.txt");


	string name;
	double payRate;
	double hours;

	infile >> name;
	while(!infile.eof()){

		infile >> payRate;
		infile >> hours;
		ppl.insert(name,payRate,hours);
		infile >> name;
	}
	infile.close();
	ppl.printPayChecks();
	return 0;
}
