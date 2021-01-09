#include "stack.h"
#include "payroll.h"

#include <iostream>



int main(){
  // testing with numbers
  Stack<int> templateTest;
  std::cout << std::endl;
  std::cout <<"Testing push with numbers : ";
  std::cout <<" 6, 11, 3" << std::endl;
  templateTest.push(6);
  templateTest.push(11);
  templateTest.push(3);
  std::cout <<" Display Stack with pushed numbers: " << std::endl;
  templateTest.display();
// Copying first stack
  std::cout <<" Copying Stack " << std::endl;
  Stack<int> Copy(templateTest);
  Copy.display();

  std::cout << std::endl;
  //Making a second stack
  std::cout <<" New Stack : " << std::endl;
  Stack <int> nStack;
  nStack.push(2);
  nStack.push(13);
  nStack.push(5);
  std::cout <<" Display new stack: " << std::endl;
  nStack.display();
  std::cout << std::endl;
// Combining both stacks
  std::cout <<"Overloading first stack with the second stack: " << std::endl;
  templateTest = nStack;
  templateTest.display();
  // Finding the top of the stack
  int topNum = templateTest.peek();

  int hold = 0;

  std::cout <<"Popping Test: " << std::endl;
  templateTest.pop(hold);
  std::cout <<" We popped Node: " << hold << std::endl;

  std::cout <<" Display Stack: " << std::endl;
  templateTest.display();
  std::cout << std::endl;

  // Testing with strings

  Stack<std::string> test2;

  std::cout <<"Pushing strings into the stack: " << std::endl;
  test2.push("Bevan");
  test2.push("Nathan");
  test2.push("Rob");
  std::cout <<"Display stack: " << std::endl;
  test2.display();

  std::cout <<" Copying stack: " << std::endl;

  Stack<std::string> copyTest2(test2);

  std::cout <<"Display copy stack: " << std::endl;
  copyTest2.display();

  std::string t = test2.peek();

  std::cout << "Top of the stack is: " << t << std::endl;
  std::string temp = " ";
  std::cout <<"Popping stack: " << std::endl;
  test2.pop(temp);

  std::cout <<" We popped : " << temp << std::endl;

  std::cout <<"Display stack : " << std::endl;

  test2.display();

  test2.pop(temp);
  std::cout <<" We popped : " << temp << std::endl;

  std::cout <<"Display stack: " << std::endl;

  //Testing Payroll

  Stack<payRoll> test3;

  payRoll Bevan("Bevan",9,9.99);
  payRoll Erin("Erin",20,17.82);
  payRoll Jack("Jack",12,7.99);

  std::cout << std::endl;

  std::cout <<" Pushing 3 employees: " << std::endl;
  test3.push(Bevan);
  test3.push(Erin);
  test3.push(Jack);

  std::cout << std::endl;

  test3.display();

std::cout <<" Copying Stack " << std::endl;

Stack<payRoll> copyTest3(test3);

std::cout <<"Printing copy version of first stack: " << std::endl;
copyTest3.display();

payRoll t3 = test3.peek();

std::cout <<" Peek of payroll stack: " << t3 << std::endl;
payRoll payRollpop ("",0,0);

std::cout << "Popping payroll stack: " << std::endl;

test3.pop(t3);

std::cout <<" Node we are popping: " << t3 << std::endl;
std::cout << "Display Employees: " << std::endl;
test3.display();

std::cout <<"Popping payrolll stack: " << std::endl;
test3.pop(t3);

std::cout <<" Node we are popping: " << t3 << std::endl;
std::cout << "Display Employees: " << std::endl;
test3.display();

return 0;



}
