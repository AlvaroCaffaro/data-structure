



template<typename T>
class Tree{
public: class iterator;
private:
	
	

	class Node{
	private:
		friend Tree;
		friend iterator;
		
		T* data;
		Node* right;
		Node* left_child;
		
	public:
		
		Node(){
			this->data = new T;
			this->left_child = nullptr;
			this->right = nullptr;
		}
		
		bool is_leaf_node(){
			return(this->left_child == nullptr);
		}
		
	};
	
	int sz;
	Node* header;
	
	
	iterator find(iterator it,T value);
	void erase_aux(Node* n);
	void height(Node* n, int h,int& maxh);
	void findMin(iterator it, iterator& min);
	void findMax(iterator it, iterator& max);
	int depth(Node* actual, Node* target, int d);
	
public:
	
	class iterator{
	private:
		friend Tree;
		
		Node* n;
		Node* father;
		Node* left;
		
	public:
		
		iterator(Node* n,Node* father, Node* left){
			this->n = n;
			this->father = father;
			this->left  = left;
		}
		
		iterator right(){
			return(iterator((this->n)->right,this->father,this->n));
		}
			
		iterator lchild(){
			return(iterator(
							((this->n)->left_child),
							this->n,
							nullptr
							)
				   );
		}
			
		bool operator==(iterator it){
			return(this->n == it.n);
		}
		
		bool operator!=(iterator it){
			return(!(*this == it));
		}
		
		T& operator*(){
			return *((this->n)->data);
		}
		
	};
	
	Tree();
	
	iterator begin();
	iterator end();
	void erase(iterator pos);
	iterator insert(iterator pos,T value);
	iterator find(T value);
	int height();
	iterator findMin();
	iterator findMax();
	int size();
	void clear();
	bool isEmpty();
	bool contains(T value);
	int depth(iterator pos);
	
	~Tree();
};
