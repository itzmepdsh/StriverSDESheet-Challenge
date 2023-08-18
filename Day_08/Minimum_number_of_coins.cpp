class Solution{

	public:
	int minCoins(int coins[], int m, int v) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(m+1,vector<int>(v+1,-1));
	    for(int j=0;j<=v;j++){
	        dp[0][j] = INT_MAX-1;
	    }
	    for(int i=0;i<=m;i++){
	        dp[i][0] = 0;
	    }
	    for(int i=1;i<=m;i++){
	        for(int j=1;j<=v;j++){
	            if(coins[i-1] <= j){
	                dp[i][j] = min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    if(dp[m][v] == INT_MAX-1)return -1;
	    return dp[m][v];
	} 
	  
};