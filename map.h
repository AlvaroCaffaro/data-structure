
#pragma once
#include "vector.cpp"


template<typename Key, typename Value>
class Pair{
public:
	Key first;
	Value second;
	Pair(){
		this->first = Key();
		this->second = Value();
	}
		
	Pair(Key first, Value second){
		this->first = first;
		this->second = second;
	}
};



template<typename Key,typename Value>
class Map: private Vector<Pair<Key,Value>>{   // implementation using order vector;
public:
	using iterator = typename Vector<Pair<Key,Value>>::iterator;
private:
	
	int find (Key key,int &min);
	int sz = 0;
public:
	
	Map();
	iterator begin();// Returns an iterator to the theoretical element that follows the last element in the map.
	int size();// – Returns the number of elements in the map.
	bool empty();// – Returns whether the map is empty.
	Pair<Key,Value>& insert(Key key, Value value); 
	int erase(iterator pos);
	int erase(Key key); 
	void clear(); // – Removes all the elements from the map.
	
	Value &operator[](Key key);
};



