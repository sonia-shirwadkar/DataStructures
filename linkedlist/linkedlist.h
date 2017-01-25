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
class MyLinkedList{
  long count;
  Node<T> *head, *tail;

  void incrementCount(){
    count++;
  }

  void decrementCount(){
    count--;
  }
  
public:
  MyLinkedList(){
    head = NULL;
    tail = NULL;
    count = 0;
  }

  ~MyLinkedList(){
    while (NULL != head){
      Node<T>* temp = head;
      delete head;
      head = head->getNext();
    }
  }

  void Append(T);
  void Insert(int, T);
  long GetSize();
  void Display();
  void Reverse();
  void Remove(int);
};

#endif	//_LL_H_
