

#include <iostream>

using namespace std;

struct Node {
  int value;
  Node* next;

  Node(){
    value = 0;
    next = NULL;
  }

  Node(int n){
    value = n;
    next = NULL;




  }
};


int total(Node* head){
  if(!head){
    return 0;
  }
  return total(head->next)+1;
}


void display(Node* head){
  if(!head){
    return;
  }
  cout<<head->value<<" "<<endl;
  return display(head->next);
}


void rvDisplay(Node* head){
  if(!head){
    return;
  }
  rvDisplay(head->next);
  cout<<head->value<<endl;
}


Node* sortedInsert(Node* head, int length){
  if(!head){
    head=new Node(length);
    return head;
  }else if(length < head->value){
    Node* temp=new Node(length);
    temp->next=head;
    return temp;
  }else if(!head->next){
    head->next=new Node(length);
    return head;
  }else if(head->next->value > length){
    Node* temp=new Node(length);
    temp->next=head->next;
    head->next=temp;
    return head;
  }
  head->next=sortedInsert(head->next, length);
  return head;
}


Node* append(Node* head, Node* head2){
    if(head -> next != NULL){
      head -> next = append(head -> next,head2);


    }else {
      head -> next = head2;
    }

    return head;

}


// Needs work
Node* rm(Node*head, int rmVal){
  if(!head){
    cout << "Not in the list." << endl;
    return head;
  }else if(head -> next && head -> next -> value == rmVal){
    Node* temp = head -> next;
    head -> next= head -> next -> next;
    delete temp;
    return head;

  }else if(head -> value == rmVal){
    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
  }
  Node* t = rm(head -> next, rmVal);
  return head;
}


Node* rv(Node* head)
{

  if(!head){
    return nullptr;
  }
  if(!head->next){
    return head;
  }
  Node* end = rv(head->next);
  end = append(end,head);
  head->next = nullptr;
  return end;
}


int main(){

Node* head = new Node(8);
head = sortedInsert(sortedInsert(sortedInsert(sortedInsert(head,11),3),7),18);

cout << "Insert and display " << endl;
display(head);

cout << endl;

cout <<"Display reversed: " << endl;

rvDisplay(head);

cout << "Removing head " << endl;

Node* rmHead = rm(head,8);

display(rmHead);


int tempLen = total(head);

cout << " Total length of list: " << tempLen << "." << endl;

cout << "Creating new list." << endl;

Node* head2 = new Node(5);
head2 = sortedInsert(sortedInsert(sortedInsert(sortedInsert(head2,44),6),22),1);

cout << " Display old list with new list " << endl;
display(head2);


cout << "Tesing reverse function: " << endl;

head = rv(head);
display(head);
// Append function not working.

cout << "Testing append function: " << endl;
head = append(head, head2);
cout << "Dislaying new list after appending." << endl;
display(head);

/*
delete head;
delete head2;
*/
return 0;



}
