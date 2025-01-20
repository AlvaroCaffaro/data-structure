#include "binaryTree.h"
#include <cassert>
using namespace std;


template<typename T>
BinaryTree<T>::BinaryTree(){
	this->header = new Node(nullptr,nullptr);
	
	this->sz = 0;
}

template<typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::begin(){
	return(iterator((this->header)->left_child,this->header,'L'));
}

template<typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::end(){
	return(iterator(nullptr,nullptr,'-'));
}

template<typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::insert(typename BinaryTree<T>::iterator pos,T value){
	assert(pos == this->end());
	
	Node* n = new Node(nullptr,nullptr); 
	*(n->data) = value; 
	this->sz +=1;

	pos.n = n;
	
	// update the father link;
	if(pos.side == 'L'){ (pos.father)->left_child = n; }
	if(pos.side == 'R'){ (pos.father)->right_child = n; }
	
	
	return(pos);
}

template<typename T>
void BinaryTree<T>::erase(Node* n){
	if(n == nullptr){
		return;
	}
	
	Node* left = n->left_child;
	Node* right = n->right_child;
	
	delete n;
	(this->sz)-=1;
	
	erase(left);
	erase(right);
	
	
}

template<typename T>
void BinaryTree<T>::erase(typename BinaryTree<T>::iterator pos){
	
	if(pos.side == 'L'){
		(pos.father)->left_child = nullptr;
	} else if(pos.side == 'R'){
		pos.father->right_child = nullptr;
	}
	
	erase(pos.n);
}


template<typename T>
int BinaryTree<T>::height(Node* current, int h, int& hmax){
	if(current == nullptr){
		return h;
	}
	
	Node* left = current->left_child;
	Node* right = current->right_child;
	
	h++;
	int h_left = this->height(left,h,hmax);
	
	if(h_left > hmax){
		hmax = h_left;
	}
	
	int h_right = this->height(left,h,hmax);
	
	if(h_right > hmax){
		hmax = h_right;
	}
	
}

template<typename T>
int BinaryTree<T>::height(){
	int h = -1;
	int hmax = -1;
	height(this->begin().n,h,hmax);
	
	return hmax;
}

template<typename T>
int BinaryTree<T>::size(){
	return this->sz;
}
	

template<typename T>
void BinaryTree<T>::depth(Node* current,Node* target,int d,int& dmax){
	if(current == nullptr){
		return;
	}
	
	d++;
	if(current == target){
		dmax = d;
		return ;
	}
	
	
	Node* left = current->left_child;
	depth(left,target,d,dmax);
	if(dmax != -1){
		return;
	}
	
	Node* right = current->right_child;
	depth(right,target,d,dmax);
	
	if(dmax != -1){
		return;
	}
	
	
	
	
}

template<typename T>
int BinaryTree<T>::depth(iterator pos){
	int d = -1;
	int dmax = -1;
	depth(this->begin(),pos.n,d,dmax);
	
	return dmax;
}


template<typename T>
void BinaryTree<T>::clear(){
	this->erase(this->begin());
}


template<typename T>
BinaryTree<T>::~BinaryTree(){
	this->clear();
	delete header;
}
