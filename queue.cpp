
#include "queue.h"

template<typename T>
Queue<T>::Queue(){
	this->sz = 0;
}

template<typename T>
bool Queue<T>::empty(){
	return (this->sz == 0);
}

template<typename T>
int Queue<T>::size(){
	return this->sz;
}

template<typename T>
T& Queue<T>::front(){
	return *(this->begin()); // list´s method
}
template<typename T>
void Queue<T>::push(T value){
	this->push_back(value);
	this->sz += 1;
}

template<typename T>
void Queue<T>::pop(){
	this->erase(this->begin()); // list's method
	this->sz -=1;
}

template<typename T>
void Queue<T>::clear(){
	this->erase(this->begin(),this->end());
	this->sz = 0;
	
}

