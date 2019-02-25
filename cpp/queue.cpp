#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
class queue{
	private:
		T *buf;
		size_t queue_len;
		int front = -1, back = -1;
	public:
		queue(int n){
			buf = (T *)malloc(sizeof(T)*n);
			queue_len = n;
		}
		void enqueue(T val){
			if (this->isFull())
				return;
			T ans = buf[++front];
		}
		T dequeue(){
			if (this->isEmpty())
				return;
			back = (back + 1)%queue_len;
			return buf[back];
		}
		bool isFull(){
			if back == front+1 || back == -1 && front == queue_len-1;
		}
		bool isEmpty(){
			return front == back;
		}
};
