#pragma once


template<typename T>
class Vector{
	
	
private:
	int sz = 0;
	int capacity = 0;
	T* data = nullptr;
	void increment_capacity();
	using iterator = int;
public:
	
	Vector(int sz);
	iterator begin();
	iterator end();
	
	int size ();
	iterator find(T value);
	void insert(iterator pos, T value);
	void erase(iterator start, iterator end);
	void erase(iterator pos);
	void pop_back();
	void pop_front();
	
	void push_back(T value);
	void push_front(T value);
	void clear();
	
	T& operator[](int n);
	
	~Vector();
		
};
