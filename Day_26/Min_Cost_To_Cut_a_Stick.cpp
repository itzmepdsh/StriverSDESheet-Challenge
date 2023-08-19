class Solution {
public:
    int fun(vector<int>& cuts, int left, int right, vector<vector<int>>& dp){
        //base case
        if(right-left <= 1)return 0;
        if(dp[left][right] != -1)return dp[left][right];
        //recursive case
        int cost = INT_MAX;
        for(int i=left+1;i<=right-1;i++){
            int leftcost = fun(cuts,left,i,dp);
            int rightcost = fun(cuts,i,right,dp);
            int currcost = (cuts[right]-cuts[left]) + leftcost + rightcost;
            cost = min(cost,currcost);
        }
        return dp[left][right] = cost;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int sz = cuts.size();
        vector<vector<int>> dp(102,vector<int>(102,-1));
        return fun(cuts,0,sz-1,dp);
    }
};