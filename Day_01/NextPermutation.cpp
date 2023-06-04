class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = n-1;
        int idx1, idx2;
        while(j>=1){
            if(nums[j-1]<nums[j]){
                idx1 = j-1;
                break;
            }
            j--;
        }
        if(j==0){
            reverse(nums.begin(),nums.end());
            return;
        }
        idx2 = idx1+1;
        for(int i=idx1+1;i<n;i++){
            if(nums[i]>nums[idx1] && nums[i]<=nums[idx1+1]){
                idx2 = i;
            }
        }
        swap(nums[idx1], nums[idx2]);
        reverse(nums.begin()+idx1+1, nums.end());
    }
};