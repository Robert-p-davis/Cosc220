#include <iostream>

#include <stdio.h>

#include "Emp.h"

#include "Exec.h"

#include "Hourly.h"

int main(){
  std::cout << "Employee 1:\n";
  Employee Roger("Roger",11.56);
  std::cout << "Display Employee\n";
  Roger.print();

  std::cout << "Testing pay() function :" << Roger.pay() << std::endl;

  Hourly hours("Roger",11.56);
  hours.addHours(13);
  std::cout << std::endl;
  std::cout << "Testing addHours() function on Employee :Roger " << std::endl;

  hours.print();

  std::cout << "Roger was paid a total of $" << hours.pay() << ".\n";
  std::cout<< std::endl;

  std::cout << "Executive 1:\n";

  Executive Laura("Laura",56.90,11000);
  std::cout << "Displaying Laura's info: \n";
  Laura.print();

  std::cout << "Testing setBonus() function: \n";
  Laura.setBonus(100000);

  Laura.print();

  std::cout << "Testing employee pointer array test.\n";

  Employee* Arr[4];

  Employee* Jen = new Employee("Jen",16.25);
  Employee* Dan = new Employee("Dan", 8.78);
  Employee* Alex = new Employee("Alex", 10.23);
  Employee* Harold = new Employee("Harold", 17.99);
  Arr[0] = Jen;
  Arr[1] = Dan;
  Arr[2] = Alex;
  Arr[3] = Harold;

  std::cout << "Printing employees: \n";
  for(int i = 0; i < 4;i++){
    Arr[i]->print();
  }
  std::cout << "Adding hours worked for each employee.\n";
// Still needs fixing.
  ((Hourly*)Arr[0])->addHours(20);
  ((Hourly*)Arr[1])->addHours(54);
  ((Hourly*)Arr[2])->addHours(12.34);
  ((Hourly*)Arr[3])->addHours(10);

  std::cout << "Printing Employees total pay: \n";
  for(int i = 0; i < 4;i++){
    Arr[i]->print();
    std::cout << "Total Pay: " << Arr[i]->pay() << std::endl;
  }




}
