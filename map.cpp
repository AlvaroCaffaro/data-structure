#include "vector.h"
#include "map.h"
#include <cmath>
using namespace std;



template<typename Key,typename Value>
int Map<Key,Value>::find(Key key,int& min){
	
	int max = this->size();
	min = 0;
	int pos = 0;
	
	int result = -1;
	while (min < max) {
		pos = (min + max) / 2; 
		
		Key currentValue = Vector<Pair<Key, Value>>::operator[](pos).first;
		if(currentValue == key){
			result = pos;
			min = pos;
			return result;
		}
		
		if (currentValue < key) {
			min = pos + 1;
		} else {
			max = pos;
		}
	}
	
	return (result);
}



template<typename Key,typename Value>
Map<Key,Value>::Map():Vector<Pair<Key,Value>>(){};


template<typename Key,typename Value>
typename Map<Key,Value>::iterator Map<Key,Value>::begin(){  // Returns an iterator to the theoretical element that follows the last element in the map.
	return(this->Vector<Pair<Key,Value>>::begin());
}

template<typename Key,typename Value>
int Map<Key,Value>::size(){ // – Returns the number of elements in the map.
	return(Vector<Pair<Key,Value>>::size());
}
template<typename Key,typename Value>
bool Map<Key,Value>::empty(){ 
	return(this->size() == 0);
}
template<typename Key,typename Value>
Pair<Key,Value>& Map<Key,Value>::insert(Key key, Value value){
	
	Pair<Key,Value> pair = Pair<Key,Value>();
	pair.first = key;
	pair.second = value;
	
	int min = 0;
	int index = this->find(key,min);
	
	iterator pos;
	if(index == -1){
		pos = this->begin()+min;
		return (*(this->Vector<Pair<Key,Value>>::insert(pos, pair)));
	}
	
	pos = this->begin() + index;
	return *(pos); 

}

template<typename Key,typename Value>
int Map<Key,Value>::erase(typename Map<Key,Value>::iterator pos){
	Vector<Pair<Key,Value>>::erase(pos);
	return 1;
}

template<typename Key,typename Value>
int Map<Key,Value>::erase(Key key){
	
	Map<Key,Value>::iterator pos = lower_bound(key);
	if(pos->first != key){
		return 0;
	}
	
	Vector<Pair<Key,Value>>::erase(pos);
	return 1;
}

template<typename Key,typename Value>
void Map<Key,Value>::clear(){
	Vector<Pair<Key,Value>>::clear();
}



template<typename Key,typename Value>
Value & Map<Key,Value>::operator[](Key key){
	
	int min = 0;
	int index = this->find(key,min);
	
	iterator pos;
	if(index == -1){
		
		Pair<Key,Value> pair = Pair<Key,Value>(key,Value());
		
		pos = this->begin()+min;
		return (this->Vector<Pair<Key,Value>>::insert(pos,pair))->second;
	}
	
	pos = this->begin() + index;
	return (pos)->second; 
	
}

