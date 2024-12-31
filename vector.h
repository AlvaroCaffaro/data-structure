#pragma once

template<typename T>
class Vector{
	
private:
	
	int sz = 0;
	int capacity = 0;
	T* data = nullptr;
	void increment_capacity();
	
public:
	
	Vector(int sz);
	int size ();
	void insert(int pos, T value);
	void erase(int start, int end) ;
	void push_back(T value);
	void push_front(T value);
	void clear();
	
	T& operator[](int n);
	
	~Vector();
		
};
