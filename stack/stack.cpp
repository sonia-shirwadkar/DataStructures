#include <iostream>
#include "stack.h"
using namespace std;


template<class T>
long MyStack<T>::GetSize(){
  return this->count;
}


template<class T>
bool MyStack<T>::isEmpty(){
  if (NULL == top)
    return true;
  return false;
}


template<class T>
void MyStack<T>::Push(T data){
  Node<T>* newNode = new Node<T>;
  newNode->setData(data);
  newNode->setNext(NULL);

  incrementCount();
  
  if (!isEmpty()){
    newNode->setNext(top);
  }

  top = newNode;
}


template<class T>
T MyStack<T>::Pop(){
  T data = T();
  
  if (isEmpty()){
    cout << "Empty stack" << endl;
    return data;
  }
  
  decrementCount();
  
  Node<T>* temp = top;

  if (top->getNext() == NULL){
    top = NULL;
  }
  else{
    top = top->getNext();
  }
  
  data = temp->getData();
  delete temp;
  return data;
}


template<class T>
T MyStack<T>::Peek(){
  T data = T();
  
  if (isEmpty()){
    cout << "Empty stack" << endl;
    return data;
  }
  
  Node<T>* temp = top;
  data = top->getData();
  return data;
}


template <class T>
void MyStack<T>::Display(){
  Node<T>* temp = top;
  while(temp != NULL){
    cout << temp->getData() << endl;
    temp = temp->getNext();
  }
}


int main(int argc, char* argv[]){
  MyStack<int> st;
  st.Push(1);
  st.Push(2);
  st.Push(3);
  st.Display();
  cout << "Pop" << endl;
  st.Pop();
  st.Display();
  cout << endl;
}
