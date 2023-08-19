// User function Template for C++

class Solution{
public:
    
    int solve(int arr[], int i, int j, vector<vector<int>>& dp){
        //base case
        if(i>=j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        //recursive case
        int min = INT_MAX;
        for(int k=i;k<=j-1;k++){
            int c1 = solve(arr,i,k,dp);
            int c2 = solve(arr,k+1,j,dp);
            int temp = c1+c2+(arr[i-1]*arr[k]*arr[j]);
            if(temp < min)min = temp;
        }
        return dp[i][j] = min;
    }
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(arr,1,n-1,dp);
    }
};