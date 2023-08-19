class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& grid, int m, int n, int i, int j){
        //base case
        if(i==m-1 && j==n-1)return grid[i][j];
        if(i==m || j==n)return INT_MAX;
        if(dp[i][j] != -1)return dp[i][j];
        //recursive case
        return dp[i][j] = grid[i][j] + min(solve(grid,m,n,i+1,j),solve(grid,m,n,i,j+1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,m,n,0,0);
    }
};