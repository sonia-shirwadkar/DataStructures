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
class MyStack{
  long count;
  Node<T> *top;

  void incrementCount(){
    count++;
  }

  void decrementCount(){
    count--;
  }
  
public:
  MyStack(){
    top = NULL;
    count = 0;
  }

  ~MyStack(){
    while (NULL != top){
      Node<T>* temp = top;
      top = top->getNext();
      delete temp;
    }
	count=0;
  }

  void Push(T);
  T Pop();
  T Peek(); 
  bool isEmpty();
  long GetSize();
  void Display();
};

#endif	//_LL_H_
