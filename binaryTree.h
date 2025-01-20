
template<typename T>
class BinaryTree{
public:
	class iterator;
private:
	class Node{
		friend BinaryTree;
		friend iterator;
	private:
		Node* left_child;
		Node* right_child;
		T* data;
	public:
		Node(){
			this->data = new T();
			this->left_child = nullptr;
			this->right_child = nullptr;
		}
		
		Node(Node* left, Node* right){
			this->data = new T();
			this->left_child = left;
			this->right_child = right;
		}
			
		~Node(){
			delete this->data;
		};
			
	};
	
	
	Node* header;
	int sz;
	
	
	void erase(Node* n);
	int height(Node* current, int h, int& hmax);
	void depth(Node* current,Node* target,int d,int& dmax);
	
	
public:
	class iterator{
		friend BinaryTree;
	private:
		Node* n;
		Node* father;
		char side; // this could be 'L' (if the node its a left-child of his father) or  'R' (its a right side)
		
		iterator(Node* n, Node* father,char side){
			this->n = n;
			this->father = father;
			this->side = side;
		}
			
		
		
		
	public:
	
		iterator left(){
			return(iterator((this->n)->left_child,this->n,'L'));
		}		
		
		iterator right(){
			return(iterator((this->n)->right_child,(this->n),'R'));
		}
		
		T& operator*(){
			return(*((this->n)->data));
		}
		
		bool operator==(iterator it){
			return((this->n) == (it.n));
		}
		
		bool operator!=(iterator it){
			return(!(this == it));
		}
		
	};
	
	BinaryTree();
	iterator begin();
	iterator end();
	
	iterator insert(iterator pos,T value);
	void erase(iterator pos);
	int height();
	int size();
	int depth(iterator pos);
	
	void clear();
	
	~BinaryTree();
	
};
