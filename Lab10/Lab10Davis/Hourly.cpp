#include "Hourly.h"

Hourly::Hourly(std::string n,double rate):Employee(n,rate){
  hours = 0;
}

void Hourly::addHours(float aHours){
  hours += aHours;
}

double Hourly::pay(){
  return payRate * hours;
}
void Hourly::print()const{
  Employee::print();
  std::cout << " Employee worked : " << hours << " hour(s)." << std::endl;
}
