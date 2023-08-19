class Solution {
public:
    bool solve(string s, unordered_set<string>& st, vector<vector<int>>& dp , int i, int j){
        //base case
        if(i>j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(st.find(s.substr(i,j-i+1)) != st.end())return dp[i][j] = 1;
        //recursive case
        for(int k=i;k<j;k++){
            if(st.find(s.substr(i,k-i+1)) != st.end() && solve(s,st,dp,k+1,j)){
                return dp[i][j] = 1;
            }
        }
        return dp[i][j] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(string str : wordDict){
            st.insert(str);
        }
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,st,dp,0,n-1);
    }
};