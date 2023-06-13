class MyQueue {
    stack<int> inp;
    stack<int> out;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inp.push(x);
    }
    
    int pop() {
        int res;
        if(!out.empty()){
            res = out.top();
            out.pop();
        }
        else{
            while(!inp.empty()){
                out.push(inp.top());
                inp.pop();
            }
            res = out.top();
            out.pop();
        }
        return res;
    }
    
    int peek() {
        if(!out.empty())return out.top();
        else{
            while(!inp.empty()){
                out.push(inp.top());
                inp.pop();
            }
        }
        return out.top();
    }
    
    bool empty() {
        return inp.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */