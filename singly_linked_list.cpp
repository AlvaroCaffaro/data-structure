
#include "singly_linked_list.h"
template <typename T>
List<T>::List() {
	this->first = (new Cell());
	this->last = this->first;
	(this->last)->next = nullptr;
}

template <typename T>
typename List<T>::iterator List<T>::begin() {
	return(iterator(this->first));
}

template <typename T>
typename List<T>::iterator List<T>::end() {
	return(iterator(this->last));
}
	
	
template <typename T>
int List<T>::size() {
	return this->sz;
}
	
template <typename T>
T List<T>::front() {
	return *(((this->first)->next)->data);
}
	
template <typename T>
T List<T>::back() {
	return *((this->last)->data);
}
	
template <typename T>
typename List<T>::iterator List<T>::next(typename List<T>::iterator p) {
	return(p.next());
}
	
template <typename T>
typename List<T>::iterator List<T>::prev(typename List<T>::iterator p) {
	auto it = iterator(this->first);
		
	while(it.next() != p){
		it++;
	}
		
	return(it);
}

template <typename T>
typename List<T>::iterator List<T>::insert(T value, typename List<T>::iterator it) {

	
	Cell* prev_cell = (it.c);
	Cell* current_cell = (it.c)->next;
	Cell* new_cell = new Cell();
	
	// link the cells ;
	prev_cell->next = new_cell;
		
	new_cell->next = current_cell;
	*(new_cell->data) = value;
	
	if(current_cell == nullptr){
		this->last = new_cell;
	}
	
	this->sz +=1;
	
	return( iterator(new_cell));
	
}


template <typename T>
void List<T>::push_back(T value) {
	/*Cell *c = new Cell();
	*(c->data) = value;
	c->next = nullptr;
		
	(this->last)->next = c;
	this->last = c;
	
	this->sz +=1;
		*/
	this->insert(value,this->end());
}
	
template <typename T>
void List<T>::push_front(T value) {
	//Cell* c = new Cell();
	//c->next = this->first;
	//*((this->first)->data) = value;
		
	//this->first = c;
	//this->sz +=1;
	
	this->insert(value,this->begin());
		
}
	

	
template <typename T>
typename List<T>::iterator List<T>::erase(typename List<T>::iterator begin, typename List<T>::iterator end) {
		
	if(begin == end){return begin;}
	
	auto it = begin.next();   
	auto finish = end.next();
	
	
	// update the link;
	Cell* prev_cell = (begin.c);  
	Cell* next_cell = (end.next()).c; 
		
	prev_cell->next = next_cell;
	
	if(end == this->end()){
		this->last = prev_cell;
	}
		
	
	// delete all the unused cell;
	auto cpy = it;
	while(it != finish){ 
			
		cpy = it + 1;
		
		delete (it.c);
		this->sz = this->sz - 1;
		it = cpy;
	
	}
	
	return iterator(prev_cell);
		
}
	
template <typename T>
typename List<T>::iterator List<T>::erase(List<T>::iterator p) {
	return erase(p,next(p));
}

template <typename T>
void List<T>::pop_back() {
	erase(this->prev(this->end()),this->end());
}
	

template <typename T>
void List<T>::pop_front() {
		
	erase(this->begin(),next(this->begin()));
	
	
	/*
		// update link
	Cell* c = (this->first)->next;
	(this->first)->next = c->next;
		
	this->sz -=1;
		// delete unused Cell
	delete c;
	
	*/
}


template<typename T>
void List<T>::clear(){
	this->erase(this->begin(),this->end());
}
	


template<typename T>
List<T>::~List(){
	this->clear();
	delete this->first;
}

