#include "Emp.h"

Employee::Employee(){
  name = "";
  payRate = 0;
}


Employee::Employee(std::string emp ,double empRate){
  name = emp;
  payRate = empRate;
}

double Employee::pay(){
  return payRate;
}

void Employee::print()const{
  std::cout << name << "'s rate of pay is " << payRate  << "." << std::endl;
}
