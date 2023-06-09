class Solution {
public:
    void generatesubsets_without_dup(vector<int>& nums, int n, vector<vector<int>>& res, vector<int> out, int idx){
        res.push_back(out);
        for(int i=idx;i<n;i++){
            if(i>idx && nums[i] == nums[i-1])continue;
            out.push_back(nums[i]);
            generatesubsets_without_dup(nums,n,res,out,i+1);
            out.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> out;
        sort(nums.begin(),nums.end());
        generatesubsets_without_dup(nums,n,res,out,0);
        return res;
    }
};