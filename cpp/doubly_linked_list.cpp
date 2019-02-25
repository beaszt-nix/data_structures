#include <iostream>
#include <new>
using namespace std;

template<class T>
class node{
	private:
		T val;
	public:
		node *prev, *next;
		node(T val){
			this->val = val;
			prev = NULL;
			next = NULL;
		}
		T data(){
			return this->val;
		}
};

template <class T>
class dll{
typedef node<T> node_t;
	private:
		node_t *root, *tail;
		int count;
	public:
		dll(){
			root = NULL;
			tail = NULL;
			count = 0;
		}
		node_t *find(T val){
			node_t *forward= root;
			node_t *backward=tail;
			if (forward == NULL)
				return NULL;
			while (forward->prev != backward){
				if (forward->data() == val)
					break;
				if (backward->data() == val)
					break;
				forward = forward->next;
				backward = backward->prev;
			}
			if (forward->prev == backward)
				return NULL;
			return forward->data() == val ? forward : backward;
		}
		void insert_head(T val){
			node_t *nnode = new node_t(val);
			if (root == NULL){
				root = nnode;
				tail = nnode;
				return;
			}
			nnode->next = root;
			root->prev = nnode;
			root = nnode;
		}
		void insert_tail(T val){
			node_t *nnode = new node_t(val);
			if (root == NULL){
				root = nnode;
				tail = nnode;
				return;
			}
			nnode->prev = tail;
			tail->next = nnode;
			tail = nnode;
		}
		void insert_after(node_t *cur, T val){
			node_t *nnode = new node_t(val);
			nnode->next = cur->next->next;
			cur->next->prev = nnode;
			nnode->prev = cur;
			cur->next = nnode;
		}
		void insert_before(node_t *cur, T val){
			node_t *nnode = new node_t(val);
			nnode->next = cur;
			nnode->prev = cur->prev;
			cur->prev->next = nnode;
			cur->prev = nnode;
		}
		void del_val(node_t *cur){
			node_t *temp = cur;
			if (temp == NULL)
				return;
			if (temp == tail){
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
				return;
			}
			if (temp == root){
				root = root->next;
				root->prev = NULL;
				delete temp;
				return;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;	
		}
		void del_head(){
			root = root->next;
			if (root == NULL){
				tail = NULL;
				return;
			}
			root->prev = NULL;
		}
		void del_tail(){
			tail = tail->prev;
			if (tail == NULL){
				root = NULL;
				return;
			}
			tail->next = NULL;
		}
		void display_forward(){
			node_t *current = root;
			while (current != NULL){
				cout << current->data() << " ";
				current = current->next;
			}
			cout << endl;
		}
		void display_reverse(){
			node_t *current = tail;
			while (current != NULL){
				cout << current->data() << " ";
				current = current->prev;
			}
			cout << endl;
		}
};
