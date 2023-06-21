class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        stack<int> st;
        vector<int> nsl(n,-1),nsr(n,n);
        //finding nearest smallest to the left
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty())nsl[i] = st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        //finding nearest smallest to the right
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty())nsr[i] = st.top();
            st.push(i);
        }
        
        vector<int> res(n,INT_MIN);
        for(int i=0;i<n;i++){
            int len = nsr[i]-nsl[i]-1;//max possible window size for which element arr[i] is eligible
            res[len-1] = max(res[len-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            res[i] = max(res[i],res[i+1]);
        }
        return res;
    }
};