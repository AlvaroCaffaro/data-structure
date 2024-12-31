#include "tree.h"
#include <cassert>
#include <iostream>
using namespace std;


template<typename T>
Tree<T>::Tree(){
	this->header = new Node();
	this->sz = 0;
	
}



template<typename T>
typename Tree<T>::iterator Tree<T>::begin(){
	return(iterator((this->header)->left_child,this->header,nullptr));
}

template<typename T>
typename Tree<T>::iterator Tree<T>::end(){
	return(iterator(nullptr,nullptr,nullptr));
}


template<typename T>
typename Tree<T>::iterator Tree<T>::insert(typename Tree<T>::iterator pos,T value){
	
	assert(!((pos.father == this->header) &&  pos.n));
	
	// define the new Node
	Node* n = new Node;
	*(n->data) = value;
	
	this->sz +=1;
	
	n->right = pos.n;
	
	pos.n = n;
	
	if(pos.left){
		(pos.left)->right = n;
	} else{
		(pos.father)->left_child = n;
	}
	
	return pos;
	
	
}

template<typename T>
void Tree<T>::erase_aux(typename Tree<T>::Node* n){
	
	if(n == nullptr){
		return;
	}
	
	Node* n_child = n->left_child;
	Node *n_aux = nullptr;
	
	delete n;
	this->sz -= 1;
	
	while(n_child != nullptr){
		
		n_aux = n_child->right;
		erase_aux(n_child);
		
		n_child = n_aux;
		
	}
	
	
	
}

template<typename T>
void Tree<T>::erase(iterator pos){
	
	if(pos == this->end()){return;}
	
	
	// update de link
	if((pos.father)->left_child == pos.n){
		(pos.father)->left_child = (pos.n)->right;
	} else{
		(pos.left)->right = (pos.n)->right;
	}
	// delete recursively;
	erase_aux(pos.n);
	
}



template<typename T>
typename Tree<T>::iterator Tree<T>::find(typename Tree<T>::iterator it,T value){
	if( *it == value){
		return it;
	}
	
	iterator child = it.lchild();
	iterator aux = this->end();
	
	while(child != this->end()){
		
		aux = find(child,value);
		if(aux != this->end()){
			return aux;
		}

		child = child.right();
		
	}
	
	
	
	return(this->end());
	
	
	
}


template<typename T>
typename Tree<T>::iterator Tree<T>::find(T value){
	
	
	return(this->find(this->begin(),value));
	
}

template<typename T>
int Tree<T>::height(Node* n, int h, int* maxh){
	
	Node* child = n->left_child;
	
	if(child == nullptr){
		return h;
	}
	
	h += 1;
	while(child != nullptr){
		
		
		h = height(child,h,maxh);
		if(h > *maxh){
			*maxh = h;
		}
		
		child = child->right;
	}
	
	return h;
	
}

template<typename T>
int Tree<T>::height(){
	int maxh = -1;
	height(this->header,-1,&maxh);
	
	return maxh;
}

template<typename T>
bool Tree<T>::isBalanced(){
	
	return false;
}

template<typename T>
void Tree<T>::findMin(iterator it, iterator &min){
	
	if(it == this->end()){
		return;
	}
	
	if(*min > *it){
		min = it;
	}
	
	iterator child = it.lchild();
	
	while(child != this->end()){
		
		findMin(child,min);
		
		child = child.right();
	}
	
	return;
}
template<typename T>
typename Tree<T>::iterator Tree<T>::findMin(){
	
	iterator min = this->begin();
	
	findMin(min, min);
	
	return min;
	
}

template<typename T>
void Tree<T>::findMax(iterator it, iterator &max){
	
	if(it == this->end()){
		return;
	}
	
	if(*max < *it){
		max = it;
	}
	
	
	iterator child = it.lchild();
	
	while(child != this->end()){
		
		findMax(child,max);
		
		child = child.right();
	}
	
	return;
}

template<typename T>
typename Tree<T>::iterator Tree<T>::findMax(){
	
	iterator max = this->begin();
	
	findMax(max, max);
	
	return max;
	
}
template<typename T>
int Tree<T>::size(){
	return this->sz;
}


template<typename T>
void Tree<T>::clear(){
	erase(this->begin());
}

template<typename T>
bool Tree<T>::isEmpty(){
	return(this->sz == 0);
}

template<typename T>
bool Tree<T>::contains(T value){
	return(find(value) != this->end());
}



template<typename T>
int Tree<T>::depth(Node* actual, Node* target, int d){
	
	if(actual == target){
		return d;
	}
	
	Node* child = actual->left_child;
	
	d = d + 1;
	
	int res = -1;
	while(child != nullptr){
		
		res = depth(child,target,d);
		if (res != -1){
			return res; 
		}
		
		child = child->right;
	}
	
	return -1;
	
	
	
}


template<typename T>
int Tree<T>::depth(iterator pos){
	return(depth(this->header,pos.n,-1));
}


/*template<typename T>
Vector<T> Tree<T>::toArray(){
	return Vector<T>(2);
}
*/

template<typename T>
Tree<T>::~Tree(){
	this->clear();
	delete this->header;
}

