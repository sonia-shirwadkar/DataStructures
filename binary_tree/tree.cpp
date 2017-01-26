#include <iostream>
#include "tree.h"
using namespace std;

template <class T>
void MyBinaryTree<T>::Insert(Node<T>* node, T data){
	if (data < node->getData()){
		if (NULL == node->getLeft())
			node->setLeft(new Node<T>(data));
		else
			Insert(node->getLeft(), data);
	}
	else{
		if (NULL == node->getRight())
			node->setRight(new Node<T>(data));
		else
			Insert(node->getRight(), data);
	}
}


template <class T>
void MyBinaryTree<T>::Insert(T data){
	if (NULL == root)
		root = new Node<T>(data);
	else
	  Insert(root, data);
}

template<class T>
bool MyBinaryTree<T>::isPresent(Node<T>* node, T item){
  if (NULL == node)
    return false;
  else if (item == node->getData())
    return true;
  else if (item < node->getData())
    return isPresent(node->getLeft(), item);
  else
    return isPresent(node->getRight(), item);  
}


template <class T>
bool MyBinaryTree<T>::isPresent(T item){
  return isPresent(root, item);
}


template <class T>
void MyBinaryTree<T>::DeleteSubtree(Node<T>* node){
  if (node != NULL){
    DeleteSubtree(node->getLeft());
    DeleteSubtree(node->getRight());
    delete node;
  }
}


template <class T>
void MyBinaryTree<T>::DeleteTree(){
  DeleteSubtree(root);
}


template <class T>
void MyBinaryTree<T>::PreOrder(Node<T>* node){
  if (node != NULL){
    cout << node->getData() << " ";
    PreOrder(node->getLeft());
    PreOrder(node->getRight());
  }
}


template <class T>
void MyBinaryTree<T>::PreOrder(){
  cout << "PreOrder: ";
  PreOrder(root);
	cout << endl << endl;
}


template <class T>
void MyBinaryTree<T>::InOrder(Node<T>* node){
  if (node != NULL){
    InOrder(node->getLeft());
    cout << node->getData() << " ";
    InOrder(node->getRight());
  }
}


template <class T>
void MyBinaryTree<T>::InOrder(){
  cout << "InOrder: ";
  InOrder(root);
 	cout << endl << endl;
}


template <class T>
void MyBinaryTree<T>::PostOrder(Node<T>* node){
  if (node != NULL){
    PostOrder(node->getLeft());
    PostOrder(node->getRight());
    cout << node->getData() << " ";
  }
}


template <class T>
void MyBinaryTree<T>::PostOrder(){
  cout << "PostOrder: ";
  PostOrder(root);
	cout << endl << endl;
}


int main(int argc, char* argv[]){
  MyBinaryTree<int> tree;

  tree.Insert(9);
  tree.Insert(4);
  tree.Insert(15);
  tree.Insert(6);
  tree.Insert(12);
  tree.Insert(17);
  tree.Insert(2);

  tree.PreOrder();
  tree.InOrder();
  tree.PostOrder();
  
  cout << "Search 5: " << tree.isPresent(5) << endl;
  cout << "Search 2: " << tree.isPresent(2) << endl;;
  
}
