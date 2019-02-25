#include <iostream>
#include <cstdlib>
using namespace std;
template<class T>
class deque{
private:
    T *buf;
public:
    int front, back, size;
    deque(int n){
        size = n;
        front = -1;
        back = size;
        buf = (T *)malloc(size * sizeof(T));
    }
    bool isFull(){
        return back == front + 1;
    }
    bool isEmpty(){
        return back == size && front == -1;
    }
    void push_front(T val){
        if (isFull())
            return;
        front++;
        buf[front] = val;
    }
    void push_back(T val){
        if (isFull())
            return;
        back--;
        buf[back] = val;
    }
    T pop_front(){
        if (isEmpty())
            return -1;
        T ans = buf[front];
        front = (front - 1);
        if (front == -1)
            front = size-1;
        if (isFull()){
            front = -1;
            back = size;
        }
        return ans;
    }
    T pop_back(){
        if (isEmpty())
            return -1;
        T ans = buf[back];
        back = (back + 1);
        if (back == size){
            back = 0;
        }
        if (isFull()){
            front = -1;
            back = size;
        }
        return ans;
    }
    T backval(){
        if (!isEmpty())
            return buf[back];
        return;
    }
    T frontval(){
        if (!isEmpty())
            return buf[front];
        return;
    }
    void display(){
        if (isEmpty())
            return;
        int i = front;
        while (i != back){
            cout << buf[i] << " ";
            i--;
            if (i == -1)
                i = size-1;
        }
        cout << buf[i] << endl;
    }
};

int main(){
    deque<int> a(5);
    cout << a.front << " " << a.back << endl
    a.push_back(1);
    cout << a.front << " " << a.back << endl;
    a.push_back(2);
    cout << a.front << " " << a.back << endl;
    a.push_front(3);
    cout << a.front << " " << a.back << endl;
    a.push_front(4);
    cout << a.front << " " << a.back << endl;
    a.push_back(5);
    cout << a.front << " " << a.back << endl;
    a.display();
    cout << a.isFull() << endl;
    while (!a.isEmpty()){
        cout << a.pop_front() << " ";;
    }
    cout << endl;
    cout << a.front << " " << a.back << endl;
    cout << a.isEmpty() << endl;
}
