#include "Exec.h"

Executive::Executive(std::string n,double p,double b){
  name = n;
  payRate = p;
  bonus = b;

}
double Executive::pay(){
  double total = Employee::pay() + bonus;
  bonus = 0;
  return total;
}

void Executive:: setBonus(double b){
  bonus = b;

}

void Executive::print(){
  Employee::print();
  std::cout << std::endl;
  std::cout << "Bonus: " << bonus << std::endl;

}
