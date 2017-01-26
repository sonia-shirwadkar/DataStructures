#ifndef _BT_H_
#define _BT_H_

template<class T>
class Node{
  T data;
  Node* left;
  Node* right;

public:
	Node(){
		this->left = NULL;
		this->right = NULL;
	}

	Node(T data){
		this->left = NULL;
		this->right = NULL;
		this->data = data;
	}

  void setData(T data){
    this->data = data;
  }

  T getData(){
    return this->data;
  }

  void setLeft(Node<T>* newNode){
    this->left = newNode;
  }

  Node<T>* getLeft(){
    return this->left;
  }

  void setRight(Node<T>* newNode){
    this->right = newNode;
  }

  Node<T>* getRight(){
    return this->right;
  }  
};


template<class T>
class MyBinaryTree{
private:
  Node<T> *root;

  bool isPresent(Node<T>*, T);
  void Insert(Node<T>*, T);
  void DeleteSubtree(Node<T>*);
  void PreOrder(Node<T>*);
  void InOrder(Node<T>*);
  void PostOrder(Node<T>*);
  
public:
  MyBinaryTree(){
    root = NULL;
  }

  ~MyBinaryTree(){
    DeleteTree();
  }

  void Insert(T);
  bool isPresent(T);
  void PreOrder();
  void InOrder();
  void PostOrder();
  void DeleteTree();
  //void Reverse();
};

#endif	//_BT_H_
