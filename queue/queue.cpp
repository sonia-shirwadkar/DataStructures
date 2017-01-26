#include <iostream>
#include "queue.h"
using namespace std;


template<class T>
long MyQueue<T>::GetSize(){
  return this->count;
}


template<class T>
bool MyQueue<T>::isEmpty(){
  if (NULL == head)
    return true;
  return false;
}


template<class T>
void MyQueue<T>::Enqueue(T data){
  Node<T>* newNode = new Node<T>;
  newNode->setData(data);
  newNode->setNext(NULL);

  incrementCount();
  
  if (isEmpty()){
    head = tail = newNode;
  }
  else{
    tail->setNext(newNode);
    tail = newNode;
  }
}


template<class T>
void MyQueue<T>::Dequeue(){
  if (isEmpty()){
    cout << "Empty queue" << endl;
    return;
  }
  
  decrementCount();
  
  Node<T>* temp = head;
  Node<T>* prev = NULL;
  
  if (NULL == head->getNext()){
    head = NULL;
    tail = NULL;
  }
  else{
    while (temp->getNext() != NULL){
      prev = temp;
      temp = temp->getNext();
    }

    prev->setNext(NULL);
  }
  
  delete temp;
  return;
}


template <class T>
void MyQueue<T>::Display(){
  Node<T>* temp = head;
  while(temp != NULL){
    cout << temp->getData() << endl;
    temp = temp->getNext();
  }
}


int main(int argc, char* argv[]){
  MyQueue<int> q;
  q.Enqueue(1);
  q.Enqueue(2);
  q.Enqueue(3);
  q.Display();
  cout << "Dequeue" << endl;
  q.Dequeue();
  q.Display();
  cout << endl;
}
