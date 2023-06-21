class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()>1){
            int a = st.top();st.pop();
            int b = st.top();st.pop();
            if(m[a][b] == 1)st.push(b);
            else st.push(a);
        }
        int pot = st.top();
        for(int j=0;j<n;j++){
            if(m[pot][j] != 0)return -1;
        }
        for(int i=0;i<n;i++){
            if(i==pot) continue;
            if(m[i][pot] != 1)return -1;
        }
        return pot;
    }
};