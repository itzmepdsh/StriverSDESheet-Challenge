#include<iostream>
using namespace std;
template<typename T>
class stack{
    private:
        T* arr;
        int n;
        int t;
    public:
        stack(int n){
            arr = new T[n];
            t = -1;
            this->n = n;
        }

        void push(T data){
            if(t == n-1){
                cout<<"Overflow!!"<<endl;
                return;
            }
            t++;
            arr[t] = data;
        }

        void pop(){
            if(t == -1){
                cout<<"Underflow!!"<<endl;
                return;
            }
            t--;
        }

        T top(){
            return arr[t];
        }

        int size(){
            return t+1;
        }

        bool empty(){
            return (t==-1);
        }
};

int main(){
    // stack<int> st(5);
    // cout<<"size: "<<st.size()<<endl;
    // cout<<"isEmpty: ";
    // st.empty()?cout<<"true"<<endl:
    //            cout<<"false"<<endl;
    // st.push(23);
    // st.push(15);
    // st.push(28);
    // st.push(65);
    // cout<<"size: "<<st.size()<<endl;
    // cout<<"Top of the stack: "<< st.top() <<endl;
    // st.pop();
    // cout<<"size: "<<st.size()<<endl;
    // cout<<"Top of the stack: "<< st.top() <<endl;

    stack<string> st(5);
    cout<<"size: "<<st.size()<<endl;
    cout<<"isEmpty: ";
    st.empty()?cout<<"true"<<endl:
               cout<<"false"<<endl;
    st.push("Pradeep");
    st.push("Sharma");
    st.push("Ravindra");
    st.push("Abhijeet");
    cout<<"size: "<<st.size()<<endl;
    cout<<"Top of the stack: "<< st.top() <<endl;
    st.pop();
    cout<<"size: "<<st.size()<<endl;
    cout<<"Top of the stack: "<< st.top() <<endl;
    return 0;
}