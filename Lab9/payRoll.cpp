#include "payroll.h"
#include <iostream>
#include <string>
//using namespace std;

payRoll::payRoll(){}

payRoll::payRoll(std::string n,double p,double h){
  setName(n);
  setRate(p);
  setHours(h);
};

double payRoll::getTotal(){
  double temp = 0;
  temp = payRate * hours;
  return temp;
}

double payRoll::getRate(){
  return payRate;
}

double payRoll::getHours(){
  return hours;
}

std::string payRoll::getName(){
  return name;

}

void payRoll::setRate(double p){
  payRate = p;
}
void payRoll::setName(std::string n){
  name = n;
}
void payRoll::setHours(double h){
  hours = h;
}

void payRoll::print(){
  std::cout <<"Name: " << this->getName() << std::endl;
  std::cout << "Pay rate: " << payRate << std::endl;
  std::cout <<"Hours: " << hours << std::endl;
  std::cout <<"Total pay: " << getTotal() << std::endl;
  std::cout <<"~~~~~~~~~~~~" << std::endl;

}

std::ostream& operator <<(std::ostream& out,payRoll& t){
  out << "Name:     ";
  out << t.getName() << std::endl;
  out << "Pay rate:     " << t.getRate() << std::endl;
  out << "Hours worked: " << t.getHours() << std::endl;
  out <<"Total pay: " << t.getTotal() << std::endl;
  out <<"~~~~~~~~~~" << std::endl;
return out;
}
