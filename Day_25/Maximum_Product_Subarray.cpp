class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN,prefixprod = 1,suffixprod = 1;
        for(int i=0;i<n;i++){
            prefixprod *= nums[i];
            suffixprod *= nums[n-i-1];
            maxi = max(maxi,max(prefixprod,suffixprod));
            if(prefixprod == 0)prefixprod = 1;
            if(suffixprod == 0)suffixprod = 1;
        }
        return maxi;
    }
};