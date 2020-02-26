#include <iostream>
#include <fstream>
#include "PayRollList.h"
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
PayRollList::PayRollList(PayRollList&newObj){
	if(newObj.head == nullptr){
		head = nullptr;
	}else {
		ListNode *curr = newObj.head;
		while(curr){
			insert(curr -> p);
			curr = curr -> next;


		}
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

}

void PayRollList:: insert(int n,PayRoll s){
	// curr(cursor) is a pointer that points to head
	ListNode* curr = head;
	// prev is a pointer that also points to head
	ListNode* prev = head;
	// newNode will be what you insert into the linked list
	ListNode* newNode = new ListNode;
	// info from new node is passed from main
	newNode -> p = s;

	newNode -> next = NULL;
// checks to see if n is in the list
	if(n > length()|| n < 0){
		cout << "Sorry you cannot insert in an invalid index.\n";
	}
	//loops through the list until n is found
	for(int i = 0;i < n;i++){
		// previous is set to the node before
		prev = curr;
		// puts the current node into the list
		curr = curr -> next;
	}
	// previous will now be the next inserted node
	prev -> next = newNode;

	newNode -> next = curr;

}


// remove function
void PayRollList::remove(int rmNode){
	ListNode* prev = head;
	ListNode* curr = head;
	if(rmNode > length()|| rmNode > 0){
		cout << "Sorry the Node you are searching for is not in this list.\n";
		cout << "List :\n";
		return;

	}
	if(rmNode == 0){
		head = head -> next;
		delete curr;
		return;
	}
	for(int i = 0;i < rmNode;i++){
		prev = curr;
		curr = curr -> next;

	}
	prev -> next = curr -> next;
	delete curr;
}
// assign function searches for certain node
void PayRollList:: assign(int x,PayRoll searchp){

	if(x > length()|| x > 0){
		cout << "Sorry the Node you are searching for is not in this list.\n";
		cout << "List :\n";

	}
		ListNode*curr = head;

	for(int i = 0;i < x;i++){
		curr = curr -> next;
		//  cursor has reached end of the list
		if(curr -> next == NULL){
			break;
		}
	}
	curr -> p = searchp;
}

int PayRollList::length(){
	 int temp = 0;
	 ListNode* curr = head;
	 while(curr){
		 temp++;
		 curr = curr ->next;
		 // if it reaches end of the list
		 if(curr -> next == NULL){
			 break;
		 }
	 }
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
