#include "double_linked_list.h"

using namespace std;
template <typename T>

List<T>::List() {
	this->last = new Cell();

	(this->last)->next = nullptr;
	(this->last)->prev = nullptr;
	this->first = this->last;
	this->sz = 0;
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
	return(this->sz);
}

template <typename T>
T& List<T>::front() {
	return *((this->first)->data);
}

template <typename T>
T& List<T>::back() {
	return *(((this->last)->prev)->data);
}

template <typename T>
typename List<T>::iterator List<T>::next(typename List<T>::iterator p) {
	return(p.next());
}

template <typename T>
typename List<T>::iterator List<T>::prev(typename List<T>::iterator p) {
	
	return p.prev();
	
}

template <typename T>
typename List<T>::iterator List<T>::insert(T value, typename List<T>::iterator it) {
	

	Cell* new_cell = new Cell();
	*(new_cell -> data) = value;
	Cell* current_cell = it.c;

	
	// update the link;
	

	if(current_cell == (this->first)){
		(this->first) = new_cell;
		new_cell->prev = nullptr;
	
	} else{
		new_cell->prev = (current_cell)->prev;
		(current_cell->prev)->next = new_cell;
	}
	
	
	(current_cell)->prev = new_cell;
	new_cell->next = current_cell;
	


	this->sz +=1;
	
	return iterator(new_cell);
	
	
}


template <typename T>
void List<T>::push_back(T value) {

	this->insert(value,this->end());
}

template <typename T>
void List<T>::push_front(T value) {
	
	this->insert(value,this->begin());
	
}



template <typename T>
typename List<T>::iterator List<T>::erase(typename List<T>::iterator begin, typename List<T>::iterator end) {

	while(begin != end){
		begin = this->erase(begin);
	}
	
	return(begin);
}

template <typename T>
typename List<T>::iterator List<T>::erase(List<T>::iterator p) {
	

	Cell* prev = (p.c)->prev;
	Cell* current = p.c;
	Cell* next = (p.c)->next;
	
	if(current == this->first){
		this->first = next;
		
	} else {
		prev->next = next;
		next->prev = prev;
	}
	
	delete (current);
	
	p.c = next;
	
	return(p);
	
}

template <typename T>
void List<T>::pop_back() {
	erase(prev(this->end()));
}


template <typename T>
void List<T>::pop_front() {
	
	erase(this->begin());
	
}


template<typename T>
void List<T>::clear(){
	this->erase(this->begin(),this->end());
	
}



template<typename T>
List<T>::~List(){
	this->clear();
	delete this->last;
}
	
	
