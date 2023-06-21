class StockSpanner {
    int d;
    stack<pair<int,int>> st;
public:
    StockSpanner() {
        d = -1;
    }
    
    int next(int price) {
        d++;
        int res;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        if(st.empty())res = d+1;
        else res = d-st.top().second;
        st.push({price,d});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */