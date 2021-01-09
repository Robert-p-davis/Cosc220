#ifndef PAYROLL_H
#define PAYROLL_H

#include <iostream>
#include <string>
//using namespace std;

class payRoll{
private:
  std::string name;
  double payRate;
  double hours;
public:
  payRoll();
  payRoll(std::string,double,double);
  double getTotal();
  double getRate();
  double getHours();
  std::string getName();
  void setRate(double);
  void setName(std::string);
  void setHours(double);

  void print();
  friend std::ostream& operator <<(std::ostream &out,payRoll&);

};

#endif
