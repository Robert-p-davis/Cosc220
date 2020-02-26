#ifndef LISTPAYROLL_H
#define LISTPAYROLL_H
#include "payroll.h"
#include <iostream>
using namespace std;

class PayRollList{
private:
	struct ListNode{
		PayRoll p;
		ListNode* next;
	};
	ListNode* head = nullptr;
	ListNode* curr = nullptr;
public:
	PayRollList();
	~PayRollList();
	//copy constructor, takes another list by reference!
	// Should copy each PayRoll into the list being instantiated
	// copy constructor
		PayRollList(PayRollList&);
	//returns the number of items in the list
	int length();

// new insert
// Inserts the PayRoll into the list so that it is now at the
// specified position (may take advantage of your operator[]).
	void insert(int,PayRoll);

	void insert(string,double,double);

	void insert(PayRoll);
	// new remove function
	void remove(int);
	// new assign function
	// Copy a PayRoll into a specific position.
// Be sure to validate the position!
// (may take advantage of your operator[])
	void assign(int,PayRoll);

	void printPayChecks();

};

#endif
