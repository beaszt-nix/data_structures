#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
class stack{
	private:
		T *buf;
		size_t top;
		size_t overflow;
	public:
		stack(int n){
			overflow = n;
			buf = (T *)malloc(sizeof(T)*n);
			top = -1;
		}
		void push(T val){
			if (this->isFull())
				return;
			buf[++top] = val;
		}
		T pop(){
			if (this->isEmpty())
				return;
			return buf[top--];
		}
		T topval(){
			if (!isEmpty())
				return buf[top];
			return;
		}
		bool isFull(){
			return top == overflow-1;
		}
		bool isEmpty(){
			return top == -1;
		}
		void peek(){
			int i = -1;
			while (i != top){
				cout << buf[++i] << " ";
			}
			cout << endl;
		}
		int size(){
			return top+1;
		}
		bool resize(int n){
			if (n < this->size())
				return false;
			T *temp = realloc(buf, n);
			buf = temp;
			overflow = n;
			return true;
		}
};