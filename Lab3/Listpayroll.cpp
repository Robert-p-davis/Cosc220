#include <iostream>
#include <fstream>
#include "Listpayroll.h"
#include "payroll.h"
using namespace std;

PayRollList::PayRollList(){
}

PayRollList::~PayRollList(){
	ListNode *curr , *temp = nullptr;
		curr  = head;
		while(curr!=nullptr){
			temp = curr->next;
			delete curr;
			curr = temp;
		}
	}

void PayRollList:: insert(string n,double pay ,double h){
// Takes name , rate, and hours worked as
// parameters for the new ListNode
	ListNode* newNode = new ListNode;
	ListNode *curr;

	newNode ->p.setName(n);
	newNode ->p.setRate(pay);
	newNode ->p.setHours(h);
	newNode->next = nullptr;


// Swapping occurs

	if(head == nullptr){
	 		head = newNode;
	}else if(newNode ->p.getRate() < head -> p.getRate()) {
			newNode -> next = head;
			head = newNode;
	}else {
		curr = head;
		while(curr->next != 0 && curr ->next->p.getRate() <= newNode ->p.getRate()){
			curr = curr ->next;

		}

		newNode ->next = curr ->next;
		curr ->next = newNode;
	}

}



void PayRollList:: insert(PayRoll emp){
	insert(emp.getName(),emp.getRate(),emp.getHours());
	/*
	ListNode *curr = head;
	curr->p = emp;


	curr->next = nullptr;
	if(head == nullptr){
		head = curr;
	}else {
		ListNode *temp = head;
		while(temp->next != nullptr){
			temp = temp ->next;
			temp ->next = temp;
		}

	}
	*/
}


void PayRollList:: printPayChecks(){
	ofstream outfile;
	outfile.open("empCash.txt");
	if(head == NULL){
		cout << "The list is empty." << endl;
		}else {
			ListNode *temp;
			 temp = head;
			while(temp){
				cout << "------------------\n";
				cout << " Name : " << temp->p.getName() << "\n";
				cout <<" " <<  temp->p.getName() << " gets an hourly pay of " << temp->p.getRate() << "$" << endl;
				cout << " and also worked a total of " << temp->p.getHours() << " hours. " << endl;
				cout << " Total Pay is : " << temp -> p.getTotal() << "$\n";
				cout << "------------------\n";
				cout << "===================\n";
				//outfile

				outfile << "------------------\n";
				outfile << " Name : " << temp->p.getName() << "\n";
				outfile <<" " <<  temp->p.getName() << " gets an hourly pay of " << temp->p.getRate() << "$" << endl;
				outfile << " and also worked a total of " << temp->p.getHours() << " hours. " << endl;
				outfile << " Total Pay is : " << temp -> p.getTotal() << "$\n";
				outfile << "------------------\n";
				outfile << "===================\n";
				temp = temp ->next;
			}


		}

}
