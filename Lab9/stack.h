#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
template <class T>

class Stack{
private:
  struct Node{
    T data;
    Node* next;
  };
  Node* top;
public:
  Stack();
  ~Stack();
  Stack<T>(const Stack&);
  Stack<T>& operator=(const Stack<T>&);
  void push(T);
  void pop(T&);
  T peek();
  void display();

};
template <class T>
Stack<T>::Stack(){
  top = nullptr;
}
template <class T>
Stack<T>::~Stack(){
  Node* curr = top;
  while(curr){
    Node* temp = curr -> next;
    delete curr;
    curr = temp;
  }
}

template <class T>
Stack<T>::Stack(const Stack& temp){
  Node* curr = temp.top;
  int count = 0;
  while(curr){
    count++;
    curr = curr -> next;
  }
  curr = temp.top;
  Node* t = temp.top;
  top = NULL;
  for(curr = temp.top;curr;curr = curr -> next){
    for(int i = 0; i < count - 1;i++){
      t = t -> next;
    }

    push(t -> data);
    t = temp.top;
    count--;
  }
}


template<class T>
  Stack<T>& Stack<T>::operator=(const Stack<T>& temp){
    int count = 0;
    Node* curr = temp.top;
    if(this == &temp){
      std::cout << "Same stack!" << std::endl;

    }
    else {
      Node* curr = this -> top;
      while(curr){
        Node* nNode = curr -> next;
        delete curr;
        curr = nNode;
      }
      curr = temp.top;
      while(curr){
        count++;
        curr = curr -> next;
      }
      curr = temp.top;
      Node* t = temp.top;
      this -> top = NULL;
      for(curr = temp.top;curr;curr = curr -> next){
        for(int i = 0;i < count - 1;i++){
          t = t -> next;
        }
        this -> push(t-> data);
        t = temp.top;
        count--;
      }

    }
      return *this;
  }



template <class T>
void Stack <T>::push(T temp){
  Node* newNode = new Node;
  newNode -> data = temp;
  newNode -> next = NULL;
  if(top == NULL){
    top = newNode;
    return;
  }else{
    newNode -> next = top;
    top = newNode;
  }
}




  template<class T>

  void Stack<T>::pop(T& temp){
    if(!top){
      std::cout <<"Empty" << std::endl;

      return;
    }else{
      Node* t = top;
      temp = top -> data;
      top = top -> next;
      delete t;
    }

  }

  template <class T>
  T Stack<T>::peek(){
    if(top){
      return top -> data;
    }else{
      std::cout <<"Empty" << std::endl;
    }
  }


  template <class T>
  void Stack<T>::display(){
    std::cout << std::endl;
    if(!top){
      std::cout << " Empty " <<std::endl;
    }
    for(Node* curr = top;curr;curr = curr -> next){
      std::cout << curr -> data << std::endl << std::endl;

    }
  }


#endif
