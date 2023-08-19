class Solution {
public:
    int LCS(string x, string y, int m ,int n, vector<vector<int>>& dp){
        //base case
        if(m==0 || n==0)return 0;
        if(dp[m][n] != -1)return dp[m][n];
        //recursive case
        if(x[m-1] == y[n-1])
            return dp[m][n] = 1+LCS(x,y,m-1,n-1,dp);
        else
            return dp[m][n] = max(LCS(x,y,m,n-1,dp),LCS(x,y,m-1,n,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return LCS(text1,text2,m,n,dp);

        for(int i=0;i<=m;i++){
            dp[i][0] = 0;
        }
        for(int j=0;j<=n;j++){
            dp[0][j] = 0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};