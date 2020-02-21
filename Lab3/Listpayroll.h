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
		public:
			PayRollList();
			~PayRollList();

		void insert(string,double,double);

		void insert(PayRoll);

		void printPayChecks();

};

#endif
