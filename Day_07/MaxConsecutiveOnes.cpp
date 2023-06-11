class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxarr = 0,max_so_far = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                max_so_far++;
            }
            else{
                max_so_far = 0;
            }
            maxarr = max(maxarr, max_so_far);
        }
        return maxarr;
    }
};