#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

template<class T>
class vector{
	private:
		size_t max_len = 5;
		T *buf;
		int back = -1;
	public:
		vector(int n){
			buf = (T *)malloc(sizeof(T) * n);
			max_len = n;
		}
		vector(){
			buf = (T *)malloc(sizeof(T) * max_len);
		}
		void resize(int n){
			max_len = n;
			T *temp = realloc(buf, max_len);
			buf = temp;
		}
		void push_back(T val){
			if (back != max_len - 1)
				buf[++back] = val;
			if ( (back + 1) > 0.75*max_len){
				this->resize(2*max_len);
			}
		}
		T pop(){
			if (back != -1)
				return buf[back--];
			return;
		}
		T pop(int i){
			T ans = buf[i];
			memmove(buf+i, buf+i+1,(back-i)*sizeof(T));
			if ( (back + 1) < 0.375*max_len)
				this->resize( max_len/2 );
			return ans;
		}
		T& operator [] (int i){
			return buf[i];
		}
		int size(){
			return back+1;
		}
};
