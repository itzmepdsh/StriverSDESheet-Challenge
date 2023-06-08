class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Time Complexity = O(n) Space Complexity = O(1)
        int n = nums.size(),element,cnt = 0;
        for(int i=0;i<n;i++){
            if(cnt == 0){
                element = nums[i];
            }
            if(nums[i] == element)cnt++;
            else cnt--;
        }
        //No need to verify since it is given majority element always exist
        return element;

        //Time Complexity = O(nlogn) Space Complexity = O(n)
        // int n = nums.size();
        // unordered_map<int,int> mp;
        // for(int num : nums){
        //     mp[num]++;
        // }
        // for(pair<int,int> pr : mp){
        //     if(pr.second > n/2){
        //         return pr.first;
        //     }
        // }
        // return -1;
    }
};
