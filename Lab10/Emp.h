#ifndef EMP_H
#define EMP_H

#include <iostream>

  class Employee{
  protected:
    double payRate;
    std::string name;

  public:
    Employee();
    Employee(std::string,double);

    virtual double pay();

    virtual void print() const;
  };

  #endif
