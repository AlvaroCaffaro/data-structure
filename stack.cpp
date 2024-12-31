#include "stack.h"

template<typename T>
Stack<T>::Stack(){
	this->sz = 0;
}

template<typename T>
bool Stack<T>::empty(){
	return (this->size() == 0);
}
	 
template<typename T>
int Stack<T>::size(){
	return this->sz;
}

template<typename T>
T& Stack<T>::top(){
	return this->back();
}
template<typename T>
void Stack<T>::push(T value){
	this->push_back(value);
	this->sz += 1;
}

template<typename T>
void Stack<T>::pop(){
	this->pop_back();
	this->sz -=1;
}

template<typename T>
void Stack<T>::clear(){
	this->erase(this->begin(),this->end());
	this->sz = 0;
	
}
