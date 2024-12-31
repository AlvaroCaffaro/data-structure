
#pragma once


template <typename T>
class List{
	public:
		class iterator;
	private:
	
	class Cell{
		friend List;
		private:
		
			friend iterator;
			friend List;
			T* data;
			Cell* next = nullptr;
		
		public:
			Cell(){
				this->data = new T;
				this->next = nullptr;
			}
		
		
			~Cell(){
				delete data;
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
					
					
			T &operator* (){
				
				return *( ((this->c)->next) ->data );  
			}
					
			void operator++(int){
				*this = iterator((this->c)->next);
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
