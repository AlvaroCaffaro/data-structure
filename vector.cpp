#include "vector.h"
#include <iostream>

using namespace std;
template<typename T>
void Vector<T>::increment_capacity(){
	if(this->capacity% 2 != 0){ 
		this->capacity +=1;
	}
	this->capacity *= 1.5;
}

template<typename T>
Vector<T>::Vector(int sz){
	
	this->sz = sz;
	this->capacity = 2* sz;
	try {
		this->data = new T[this->capacity];
		
	} 
	catch (const exception ex){
		cerr <<"Error al reservar la memoria:" << ex.what();
	} 

}
template<typename T>
int Vector<T>::size (){
	return this->sz;
}


template<typename T>
void Vector<T>::insert(int pos, T value){
	this->sz +=1;
	if (this->sz == this-> capacity){
		this->increment_capacity();
		T *cpy = new T [this->capacity];
		
		int i= pos; int j=pos;
		
		while (i < (this->sz -1) ){ // cause we aummented  
			if ( j == pos){ j++; }
			*(cpy + j) = *(this->data +i);
			i++;
			j++;
		}
		*(cpy + pos) = value;              
		delete [] this->data;
		this->data = cpy;
		return;
		
	}
	int i = this->sz ; 
	while(i > pos) {
		*(this->data + (i  + 1)
		  ) = *(this->data + i);
		i --;
	}
	*(this->data+pos) = value;
	this->sz -=1;
	
}

template<typename T>
void Vector<T>::erase(int start, int end) {
	int i = 0;
	while  (end + i <  this->sz){
		
		*(this->data + (start + i) ) = *(this->data +(end + i));
			
		i++;
	}
	this->sz -= (end - start);
}

template<typename T>
void Vector<T>::push_back(T value){
	insert(this->sz,value);
}

template<typename T>
void Vector<T>::push_front(T value){
	insert(0,value);

} 
template<typename T>
void Vector<T>::clear(){
	delete [] this->data;
	this-> data = nullptr;
	this-> sz = 0;
	this-> capacity = 0;
}

template<typename T>
T& Vector<T>::operator[](int n){
	return *(this->data + n);
}

template<typename T>
Vector<T>::~Vector(){
	this->clear();
}


