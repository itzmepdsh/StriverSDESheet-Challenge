#include<iostream>
using namespace std;

template<typename T>
class ListNode{
    public:
        T val;
        ListNode<T>* next;
        ListNode(T val){
            this->val = val;
            this->next = NULL;
        }
};

template<typename T>
class stack{
    private: 
        ListNode<T>* head;
        int cnt;//size of the stack
    
    public: 
        stack(){
            head = NULL;
            cnt = 0;
        }

        void push(T data){
            ListNode<T>* n = new ListNode<T>(data);
            n->next = head;
            head = n;
            cnt++;
        }

        void pop(){
            if(head == NULL){
                cout<<"underflow"<<endl;
                return;
            }
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
            cnt--;
        }

        T top(){
            return head->val;
        }

        int size(){
            return cnt;
        }

        bool empty(){
            return (cnt==0);
        }
};

int main(){
    stack<string> st;
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