#include <iostream>
#include <fstream>
#include "PayRollStack.h"
#include "payroll.h"
using namespace std;
/* Robert Davis
COSC-220
Salisbury University
*/
int main(){
  // created object
  PayRollStack ppl;

  string name;
  double payRate;
  double hours;
//  int funcChoice;

  ifstream infile;
  ofstream outfile;
  infile.open("emp.txt");


     while(!infile.eof()){
       infile >> name;
       infile >> payRate;
       infile >> hours;

    PayRoll newEmployee (name,payRate,hours);
    ppl.push(newEmployee);
  }
  infile.close();


  PayRoll emp("Carrol",12,29);
  ppl.push(emp);
  PayRoll emp2("Steve",20,47);
  ppl.push(emp2);
  cout << " Pushed in Steve and Carrol to the stack.\n";
  PayRollStack poptest;
  poptest = ppl;

  int num = 0;
//  num = ppl.size();
  for(num = ppl.size();num>=0;num--){
    PayRoll temp = ppl.pop();
    temp.empInfo();
    cout << endl << endl;

  }
  ppl.pop();
  cout << "testing = operator \n";

  //num = popTest.size();
  for(num = poptest.size();num >=0;num--){
    PayRoll newTemp = poptest.pop();
    newTemp.empInfo();
    cout << endl << endl;
  }
  return 0;
}
