

#include "vector.h"
#include <iostream>

using namespace std;

template<typename T>
void Vector<T>::increment_capacity(){
	
	if(this->capacity == 0){
		this->capacity = 1;
	}

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
		for(int i = 0; i < this->sz; i++){
			*(this->data + i) = T();
		}
		
	} 
	catch (const exception ex){
		cerr <<"Error al reservar la memoria:" << ex.what();
	} 

}

template<typename T>
Vector<T>::Vector(){
	this->sz = 0;
	this->capacity = 0;;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::begin(){
	return (this->data);
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end(){
	return (this->data + this->sz);
}


template<typename T>
int Vector<T>::size (){
	return this->sz;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::find(T value){
	int i = 0;
	while(i < this->sz){
		
		if(*(this->data + i) == value) return (this->data + i);
		
		i++;
	}
		
	
	return this->end();
	
	
	
}



template<typename T>
typename Vector<T>::iterator Vector<T>::insert(typename Vector<T>::iterator pos, T value){
	
	int index = (pos - this->data); // index of the position
	
	if (this->sz == this->capacity){
		this->sz +=1;
		
		this->increment_capacity();
		
		T *cpy = new T [this->capacity];
		
		
		int i= 0; int j=0;
		
		while (i < (this->sz - 1) ){ // cause we aummented sz so we use sz-1
			
			if ( j == index){ j++; }
			*(cpy + j) = *(this->data + i);
			i++;
			j++;
		}
		*(cpy + index) = value;
		
		delete [] this->data;
		this->data = cpy;
		
		return (this->data + index);
		
	}
	
	int i = this->sz - 1;
	while(i >= index) {
		*(this->data + (i + 1)) = *(this->data + i);
		i--;
	}
	
	*(this->data + index) = value;
	this->sz +=1;
	
	return (this->data + index);
	
}

template<typename T>
void Vector<T>::push_back(T value){
	insert(this->end(),value);
}

template<typename T>
void Vector<T>::push_front(T value){
	insert(this->begin(),value);
} 

template<typename T>
typename Vector<T>::iterator Vector<T>::erase(typename Vector<T>::iterator start, typename Vector<T>::iterator end) {
	
	int diff = end - start; 
	
		if(diff <= 0){ // the case that the end its the same to the start or the start is next to the end;
			return end;
		}

	
	int i = 0;
	while ( (end + i) != (this->data + this->sz) ){
		
		*(start + i)  = *(end + i);
		i++;
		
	}
	
	this->sz -= (diff);
	
	return end;
	
}


template<typename T>
typename Vector<T>::iterator Vector<T>::erase(typename Vector<T>::iterator pos) {
	return erase(pos,pos + 1); 
}

template<typename T>
void Vector<T>::pop_back(){
	erase(this->end() - 1);
}

template<typename T>
void Vector<T>:: pop_front(){
	erase(this->begin());
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


