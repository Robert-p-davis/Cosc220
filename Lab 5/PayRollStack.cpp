#include <iostream>
#include <fstream>
#include "PayRollStack.h"
#include "payroll.h"
using namespace std;

PayRollStack::PayRollStack(){
	head = NULL;
}

PayRollStack::~PayRollStack(){
	StackNode* curr = head;
	while(curr){
		curr = curr -> next;
		delete curr;
		curr = head;
	}
}

	PayRollStack ::PayRollStack(const PayRollStack& temp){
		if(temp.head ==NULL){
			head = NULL;

		}else {
			StackNode* curr = temp.head;
			while(curr){
				push(curr-> p);
				curr = curr -> next;
			}
		}

	}
	// Make it return an object not a pointer of an object
	PayRollStack PayRollStack:: operator=(const PayRollStack& q){
		StackNode *curr = q.head;
		while(curr){
			push(curr -> p);
			curr = curr -> next;

		}
		return this;
	}
void PayRollStack::push(PayRoll p){

	StackNode* curr = head;
	StackNode* newNode = new StackNode;
	newNode -> p = p;
	newNode -> next = NULL;
	if(head==NULL){
		head = newNode;
		return;
	}
	while(curr -> next){
		curr = curr -> next;

	}
	curr -> next = newNode;
}

PayRoll PayRollStack::pop(){
	StackNode* curr = head;
	StackNode* previous = head;
	PayRoll newEmp("Elizabeth",18,39);
	if(head == NULL){
		cout <<" The Stack is empty. Nothing to pop.\n";
		return newEmp;
	}
	if(!head -> next){
		newEmp = head -> p;
		delete head;
		head = NULL;
		return newEmp;

	}
	while(curr -> next){
		previous = curr;
		curr = curr -> next;

	}
	previous -> next = NULL;
	newEmp = curr -> p;
	 delete curr;
	 return newEmp;

}

/*void PayRollStack::pop(PayRoll& ){


}
*/
int PayRollStack::size(){
	StackNode* curr = head;
	int total = 0;
	while(curr){
		total++;
		curr = curr -> next;
	}
	return total;

}
