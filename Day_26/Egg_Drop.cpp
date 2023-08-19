class Solution {
public:
    int dp[101][10001];
    int solve(int e, int f){
        //base case
        if(f==0 || f==1)
            return f;
        if(e==1)
            return f;
        if(dp[e][f] != -1)return dp[e][f];
        //recursive case

        // int mn = INT_MAX;
        // for(int k=1;k<=f;k++){
        //     int temp = 1 + max(solve(e-1,k-1),solve(e,f-k));
        //     mn = min(mn,temp);
        // }
        
        int mn = INT_MAX,low,high;
        int l = 1,h = f;
        while(l<=h){
            int mid = (l+h)>>1;
            if(dp[e-1][mid-1] != -1)
                low = dp[e-1][mid-1];
            else
                low = solve(e-1,mid-1);
            if(dp[e][f-mid] != -1)
                high = dp[e][f-mid];
            else
                high = solve(e,f-mid);
            int temp = 1 + max(low,high);
            mn = min(mn,temp);
            if(low < high)
                l = mid+1;
            else
                h = mid-1;
        }
        return dp[e][f] = mn;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};