#include "double_linked_list.cpp"

template<typename T>
class Stack: private List<T>{
private:
	int sz;
public:
	Stack();
	bool empty(); 
	int size();
	T& top(); 
	void push(T value);
	void pop(); 
	void clear();
	
};
