class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int memoization(int w, int wt[], int val[], int n, vector<vector<int>>& t){
        //base case
        if(n==0 || w==0)return 0;
        
        if(t[n][w] != -1)return t[n][w];
        //choice cases
        if(wt[n-1] <= w){
            return t[n][w] = max((val[n-1] + memoization(w-wt[n-1],wt,val,n-1,t)),memoization(w,wt,val,n-1,t));
        }
        else return t[n][w] = memoization(w,wt,val,n-1,t);
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        // vector<vector<int>> t(n+1,vector<int>(W+1,-1));
        // return memoization(W,wt,val,n,t);
        
        vector<vector<int>> t(n+1,vector<int>(w+1,-1));
        //Base case initialization 
        for(int i=0;i<=n;i++){
            t[i][0] = 0;
        }
        for(int j=0;j<=w;j++){
            t[0][j] = 0;
        }
        
        //choice filling 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(wt[i-1] <= j){
                    t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][w];
    }
};