#include <iostream>
#include <new>

template<class T>
class node{
	private:
		T val;
	public:
		node_t *next;
		node(T val){
			this->val = val;
			next = NULL;
		}
		node *next(){
			return next;
		}
		T node_val(){
			return val;
		}
};

template<class T>
class linked_list{
typedef node<T> node_t;
	private:
		node_t *root;
		size_t count;
		node_t *tail;
	public:
		linked_list(){
			root = NULL;
			tail = NULL;
			count = 0;
		}
		void insert_head(T val){
			node_t *nnode = new node_t(val);
			nnode->next = root;
			root = nnode;
			count++;
			if (count ==  1)
				tail = root;
		}
		void insert_tail(T val){
			if (root == NULL){
				this->insert_head(val);
				return;
			}
			node_t *nnode = new node_t(val);
			tail->next = nnode;
			tail = nnode;
			count++;
		}
		void insert(node_T *pred, T val){
			if (pred == NULL){
				this->insert_head(val);
				return;
			}
			node_t *nnode = new node_t(val);
			nnode->next = pred->next;
			pred->next = nnode;
		}
		node_t *find(T val){
			node_t *cur_pred = NULL, *current = root;
			while (current != NULL){
				cur_pred = current;
				if (val != current->val)
					current = current->next;
			}
			return cur_pred;
		}
		void del_head(){
			node_t *temp = root;
			root = root->next;
			delete temp;
			count--;
			if (count == 0)
				tail = NULL;
		}
		void del_af(node_t *pred){
			if (pred == NULL){
				this->del_head();
				return;
			}
			if (pred == tail){
				return;
			}
			node_t *temp = pred->next;
			pred->next = pred->next->next;
			count--;
			if (temp == tail)
				tail = pred;
			delete temp;
		}
		int size(){
			return count;
		}
		void display(){
			node_t *current = root;
			while (current != NULL){
				cout << current->val << " ";
			}
			cout << endl;
		}
		node_t *begin(){
			return root;
		}
		node_t *end(){
			return tail;
		}
};
