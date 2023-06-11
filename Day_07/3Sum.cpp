class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i] == nums[i-1])continue;
            int j=i+1,k=n-1;
            int last_j = INT_MIN, last_k = INT_MIN;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    if(nums[j] == last_j){
                        j++;
                        continue;
                    }
                    if(nums[k] == last_k){
                        k--;
                        continue;
                    }
                    res.push_back({nums[i],nums[j],nums[k]});
                    last_j = nums[j];
                    last_k = nums[k];
                }
                else if(sum < 0)j++;
                else k--;
            }
        }
        return res;
    }
};