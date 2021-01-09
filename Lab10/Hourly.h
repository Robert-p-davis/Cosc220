#ifndef HOURLY_H
#define HOURLY_H

#include "Emp.h"
#include "Exec.h"

#include <iostream>

class Hourly: public Employee{
private:
  float hours;
public:
  Hourly(std::string,double);
  void addHours(float);
  double pay() override;
  void print() const override;
};
#endif
