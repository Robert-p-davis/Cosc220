#include <iostream>
#include <fstream>
#include "PayRollList.h"
#include "payroll.h"
using namespace std;
/* Robert Davis
COSC-220
Salisbury University
*/
int main(){
  // created object
  PayRollList ppl;

  string name;
  double payRate;
  double hours;
  int funcChoice;

  ifstream infile;
  ofstream outfile;
  infile.open("emp.txt");
  cout << "======================================================================\n";
  cout << " Enter [1] for insert function or Enter [2] for insert function 2: \n";
  cout << "=======================================================================\n";
  cin >> funcChoice;

  if(funcChoice != 1 && funcChoice != 2){
    cout << "Invalid choice. Enter [1] or [2].\n";
    cin >> funcChoice;
  }else {
      infile >> name;
     while(!infile.eof()){
    infile >> payRate;
    infile >> hours;
    if(funcChoice == 1){

      infile >> payRate;
      infile >> hours;
      ppl.insert(name,payRate,hours);
      infile >> name;


    }
    PayRoll x(name,payRate,hours);
    if(funcChoice == 2){
      ppl.insert(x);
    }
  }
}

  cout << "Original Linked List: \n" << endl;
  cout << "=======================================\n";
  ppl.printPayChecks();
  //copy linked list to the copy constructor
  PayRollList cpy(ppl);
  cout << endl << endl;
  cout << " Copy Constructor is in effect. Lets test it out:\n";
  cpy.printPayChecks();
  // adding a new object
  PayRoll newObject("Jackson",31.87,14);
  // assigning it to index 2
  cpy.assign(2,newObject);
  cout << "A new object has been added to index 2 of the linked list! Lets test it out.\n";
  cpy.printPayChecks();
  // remove object at index 4
  cpy.remove(4);
  cout << " Object at index 4 has been removed! lets test it out:\n";
  cpy.printPayChecks();


  return 0;
}
