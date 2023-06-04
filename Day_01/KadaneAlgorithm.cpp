class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum = nums[0], maxsum = nums[0];
        for(int i=1;i<nums.size();i++){
            cursum = max(cursum+nums[i],nums[i]);
            maxsum = max(maxsum,cursum);
        }
        return maxsum;
    }
};