class MinStack {
    stack<int> org_stk;
    stack<int> min_stk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        org_stk.push(val);
        if(min_stk.empty() || min_stk.top() >= val)min_stk.push(val);
    }
    
    void pop() {
        int tp = org_stk.top();
        org_stk.pop();
        if(min_stk.top() == tp)min_stk.pop();
    }
    
    int top() {
        return org_stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */