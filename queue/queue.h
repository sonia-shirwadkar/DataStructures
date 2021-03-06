#ifndef _LL_H_
#define _LL_H_

template<class T>
class Node{
  T data;
  Node *next;

public:
  void setData(T data){
    this->data = data;
  }

  T getData(){
    return this->data;
  }

  void setNext(Node<T>* newNode){
    this->next = newNode;
  }

  Node<T>* getNext(){
    return this->next;
  }
};


template<class T>
class MyQueue{
  long count;
  Node<T> *head, *tail;

  void incrementCount(){
    count++;
  }

  void decrementCount(){
    count--;
  }
  
public:
  MyQueue(){
    head = NULL;
    tail = NULL;
    count = 0;
  }

  ~MyQueue(){
    while (NULL != head){
      Node<T>* temp = head;
      head = head->getNext();
      delete temp;
    }
	tail=NULL;
	count=0;
  }

  void Enqueue(T);
  T Dequeue();
  bool isEmpty();
  long GetSize();
  void Display();
};

#endif	//_LL_H_
