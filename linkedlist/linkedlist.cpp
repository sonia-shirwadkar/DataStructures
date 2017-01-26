#include <iostream>
#include "linkedlist.h"
using namespace std;


template<class T>
long MyLinkedList<T>::GetSize(){
  return this->count;
}


template<class T>
void MyLinkedList<T>::Append(T data){
  if (NULL == head){
    this->Insert(1, data);
  }
  else{
    this->Insert(GetSize()+1, data);
  }
}


template<class T> void MyLinkedList<T>::Display(){
  if (head == NULL)
    return;

  Node<T>* temp = head;
  while (temp){
    cout << temp->getData() << endl;
    temp = temp->getNext();
  }
}


template<class T>
void MyLinkedList<T>::Insert(int pos, T data){
  int i;

  if (pos <= 0 || pos > (GetSize()+1)){
    cout << "Invalid position" << endl;
    return;
  }
  
  Node<T>* newNode = new Node<T>;
  newNode->setData(data);
  newNode->setNext(NULL);

  this->incrementCount();
  
  if (pos == 1){
    if (NULL == head){
      head = tail = newNode;
    }
    else{
      newNode->setNext(head);
      head = newNode;
    }
    
    return;
  }

  Node<T> *temp = head; 
  for (i = 1; i < pos-1; i++){
    temp = temp->getNext();
  }

  if (NULL == temp->getNext()){
    tail = newNode;
  }
  
  newNode->setNext(temp->getNext());
  temp->setNext(newNode);
  return;
}


template<class T>
void MyLinkedList<T>::Reverse(){
  Node<T>* current, *next, *prev;
  current = head;

  if (NULL != head){
    tail = head;
  }
  
  prev = NULL;
  while (current != NULL){
    next = current->getNext();
    current->setNext(prev);
    prev = current;
    current = next;
  }

  head = prev;
}


template<class T>
void MyLinkedList<T>::Remove(int pos){
  int i;

  if (pos <= 0 || pos > (GetSize()) || NULL == head){
    cout << "Invalid position" << endl;
    return;
  }
  
  this->decrementCount();
  
  if (pos == 1){
    Node<T>* temp = head;
    
    if (NULL == head->getNext()){
      head = NULL;
      tail = NULL;
    }
    else{
      head = head->getNext();
    }

	temp->setNext(NULL);
    delete temp;
    return;
  }

  Node<T> *temp , *prev;
  temp = prev = head;
  
  for (i = 1; i <= pos-1; i++){
    prev = temp;
    temp = temp->getNext();
  }

  if (NULL == temp->getNext()){
    tail = prev;
  }

  prev->setNext(temp->getNext());
  temp->setNext(NULL);
  delete temp;
  return;    
}


int main(int argc, char* argv[]){
  MyLinkedList<int> list;
  list.Insert(1,101);
  list.Insert(2,102);
  list.Insert(3,103);
  //list.Insert(4,104);
  list.Insert(5,105);
  //list.Append(1);
  //list.Append(2);
  //list.Append(3);
  list.Insert(1, 0);
  list.Insert(2, 1);
  list.Display();
  cout << endl << "Reverse:" << endl;
  list.Reverse();
  list.Display();
  cout << "Before delete:" << endl;
  list.Remove(5);
  list.Display();
}
