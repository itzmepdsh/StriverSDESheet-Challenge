#include<iostream>
using namespace std;

template<typename T>
class Circular_queue{
    T* arr;
    int r;
    int f;
    int n;
    int cnt;
    public:
        Circular_queue(int n){
            arr = new T[n];
            r = -1;
            f = -1;
            this->n = n;
            cnt = 0;
        }

        bool isFull(){           
            if(f==(r+1)%n)return true;
            return false;
        }

        void push(T val){
            if(isFull()){
                cout<<"Queue is Full."<<endl;
                return;
            }
            if(f == -1){
                f = 0;
            }
            r = (r+1)%n;
            arr[r] = val;
            cnt++;
        }

        bool empty(){
            if(f==-1)return true;
            return false;
        }

        void pop(){
            if(empty()){
                cout<<"Queue is empty."<<endl;
                return;
            }
            if(f==r){
                f = -1;
                r = -1;
            }
            else{
                f = (f+1)%n;
            }
            cnt--;
        }

        T front(){
            return arr[f];
        }

        int size(){
            return cnt;
        }

        void display(){
            if(empty()){
                return;
            }
            for(int i=f;i!=r;i = (i+1)%n){
                cout<<arr[i]<<" ";
            }
            cout<<arr[r]<<endl;
        }
};
int main(){
    Circular_queue<int> q(5);
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
    q.push(34);
    q.display();
    cout<<endl;
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
    //cout<<q.front()<<endl;
    cout<<"Size: "<<q.size()<<endl;
    cout<<"Is Empty: ";
    q.empty()?cout<<"Queue is empty."<<endl:
              cout<<"Queue is not empty."<<endl;
    return 0;
}