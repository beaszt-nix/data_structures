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
		void insert(T val){
			node_t *current = root;
			while (current != NULL){
				if (current->data() < val )
					current = current->next;
			}
			node_t *nnode = new node_t(val);
			count++;
			if (root == NULL){
				root =nnode;
				tail =nnode;
				return;
			}
			if (current == NULL){
				tail->next = nnode;
				nnode->prev = tail;
				tail = tail->next;
				return;
			}
			nnode->next = current;
			nnode->prev = current->prev;
			current->prev->next=nnode;
			current->prev=nnode;
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
		void display_ascending(){
			node_t *current = root;
			while (current != NULL){
				cout << current->data() << " ";
				current = current->next;
			}
			cout << endl;
		}
		void display_decreasing(){
			node_t *current = tail;
			while (current != NULL){
				cout << current->data() << " ";
				current = current->prev;
			}
			cout << endl;
		}
		node_t *find(T val){
			node_t *current = root;
			while (current != NULL){
				if (current->data() == val)
					return current;
			}
			return current;
		}
		void reverse(){
			node_t *current=root, *temp;
			while (current != NULL){
				temp = current->next;
				current->next=current->prev;
				current->prev=temp;
				current=temp;
			}
			temp = root;
			root = tail;
			tail = root;
		}
};

int main(){
;
}
