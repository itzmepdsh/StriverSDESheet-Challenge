class Solution {
public:
    void solve(vector<int>& nums,int n, vector<vector<int>>& res, int i){
        //base case
        if(i==n){
            res.push_back(nums);
            return;
        }
        //recursive case
        for(int j=i;j<n;j++){
            swap(nums[j],nums[i]);
            solve(nums,n,res,i+1);
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        solve(nums,n,res,0);
        return res;
    }
};