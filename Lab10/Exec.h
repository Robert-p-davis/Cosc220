#ifndef EXEC_H
#define EXEC_H
#include "Emp.h"

#include <iostream>

class Executive: public Employee{
private:
    double bonus;
public:
  Executive(std::string,double,double);
  void setBonus(double);
  double pay();
  void print();
};

#endif
