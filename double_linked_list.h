#pragma once

template <typename T>
class List{
public:
	class iterator;
private:
	
	class Cell{
		
	private:
		friend List;
		friend iterator;
		T* data;
		Cell* next;
		Cell* prev;
		
	public:
		Cell(T value){
			this->data = new T(value);
			this->next = nullptr;
			this->prev = nullptr;
		}
		
		Cell(){
			this->data = new T;
			this->next = nullptr;
			this->prev = nullptr;
		}
		
		
		~Cell(){
			delete this->data;
		}
			
	};
	
	int sz = 0;
	Cell* first = nullptr;
	Cell* last = nullptr;
	
public:
	
	class iterator{
	private:
		friend List;
		Cell* c;
		
		iterator(Cell* c){
			this->c = c;
		}
			
			
	public:
				
			iterator next(){
				return iterator((this->c)->next);
			}
			
			iterator prev(){
				return iterator((this->c)->prev);
			}
			
					
					
			T &operator* (){
				return *((this->c)->data );  
			}
				
			void operator++(int){
				
				*this = iterator((this->c)->next);
			}					
				
			void operator--(int){
				*this = iterator((this->c)->prev);
			}
			
			
				
					
			iterator operator+(int n){
				Cell* c = (this->c);
				int i = 0;
				while(i < n){
					c = c->next;
					i++;
				}
						
				return(iterator(c));
			
			}
					
				
			bool operator==(iterator it){
				return((this->c) == (it.c));
			}
					
			bool operator!=(iterator it){
				return (!(*this == it));
			}
					
					
	};	
	
	
	List();
	
	int size();
	iterator begin();
	iterator end();
	
	T front();
	T back();
	
	iterator next(iterator p);
	iterator prev(iterator p);
	
	iterator insert(T value,List<T>::iterator it);
	
	void push_back(T value);
	void push_front(T value);
	
	iterator erase(iterator start,iterator end);
	iterator erase(iterator p);
	void pop_back();
	void pop_front();
	
	void clear();
	
	~List();
	
	
	
	
};
