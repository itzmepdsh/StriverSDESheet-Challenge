#include<iostream>
using namespace std;

template<typename T>
class Queue{
    T* arr;
    int f;//idx where last pop opertion is performed
    int r;//idx where last push opertion is performed
    int n;
    public:
        Queue(int n){
            arr = new T[n];
            f = -1;
            r = -1;
            this->n = n;
        }

        void push(T data){
            if(r==n-1){
                cout<<"Overflow!! Queue is full"<<endl;
                return;
            }
            r += 1;
            arr[r] = data;
        }

        void pop(){
            if(f==r){
                cout<<"Queue is empty. Underflow!!"<<endl;
                return;
            }
            f += 1;
        }

        T front(){
            return arr[f+1];
        }

        int size(){
            return r-f;
        }

        bool empty(){
            return (r==f);
        }
};

int main(){
    Queue<int> q(5);
    cout<<"Size: "<<q.size()<<endl;
    cout<<"Is Empty: ";
    q.empty()?cout<<"Queue is empty."<<endl:
              cout<<"Queue is not empty."<<endl;
    q.push(98);
    q.push(34);
    q.push(12);
    q.push(121);
    q.push(-1);
    q.push(21);
    cout<<"Front: "<<q.front()<<endl;;
    cout<<"Size: "<<q.size()<<endl;
    cout<<"Is Empty: ";
    q.empty()?cout<<"Queue is empty."<<endl:
              cout<<"Queue is not empty."<<endl;
    q.pop();
    cout<<"Size: "<<q.size()<<endl;
    cout<<"Is Empty: ";
    q.empty()?cout<<"Queue is empty."<<endl:
              cout<<"Queue is not empty."<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<"Size: "<<q.size()<<endl;
    cout<<"Is Empty: ";
    q.empty()?cout<<"Queue is empty."<<endl:
              cout<<"Queue is not empty."<<endl;
    q.pop();
    q.push(34);
    cout<<q.front()<<endl;
    cout<<"Size: "<<q.size()<<endl;
    cout<<"Is Empty: ";
    q.empty()?cout<<"Queue is empty."<<endl:
              cout<<"Queue is not empty."<<endl;
    return 0;
}