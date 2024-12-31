#include "double_linked_list.cpp"
template<typename T>
class Queue: private List<T>{
private:
	int sz;
public:
	Queue();
	bool empty();
	int size();
	T& front();
	void pop();
	void push(T value);
	void clear();
	
};
