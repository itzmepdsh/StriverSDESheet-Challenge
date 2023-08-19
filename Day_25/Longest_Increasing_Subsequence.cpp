class Solution {
public:
    int solve(vector<int>& nums, int n, int idx, int prev_idx, vector<vector<int>>& dp){
        //base case
        if(idx == n)
            return 0;
        if(dp[idx][prev_idx+1] != -1)return dp[idx][prev_idx+1];
        //recursive case
        int take=0,nottake=0;
        if(prev_idx == -1 || nums[idx] > nums[prev_idx])
            take = 1+solve(nums,n,idx+1,idx,dp);
        nottake = solve(nums,n,idx+1,prev_idx,dp);
        return dp[idx][prev_idx+1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i=1;i<n;i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int idx = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return len;
        
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solve(nums,n,0,-1,dp);

        // vector<int> curr(n+1,-1), next(n+1,-1);
        // for(int i=0;i<=n;i++){
        //     next[i] = 0;
        // }
        // for(int idx = n-1;idx>=0;idx--){
        //     for(int prev_idx = idx-1;prev_idx>=-1;prev_idx--){
        //         int take=0,nottake=0;
        //         if(prev_idx == -1 || nums[idx] > nums[prev_idx])
        //             take = 1+next[idx+1];
        //         nottake = next[prev_idx+1];
        //         curr[prev_idx+1] = max(take,nottake);
        //     }
        //     next = curr;
        // }
        // return curr[0];
    }
};