class Solution {
public:
    int dp[2001][2001];
    bool isPalindrome(string& s, int i, int j){
        while(i<j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string& s, int i ,int j){
        //base case
        if(i>j)return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(isPalindrome(s,i,j))
            return dp[i][j] = 0;
        //recursive case
        int mn = INT_MAX;
        for(int k=i;k<=j-1;k++){
            if(isPalindrome(s,i,k)){
                int temp = 1+solve(s,k+1,j);
                mn = min(mn,temp);
            }
        }
        return dp[i][j] = mn;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.length();
        return solve(s,0,n-1);
    }
};