class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        for(pair<int,int> pr : mp){
            if(pr.second > n/2){
                return pr.first;
            }
        }
        return -1;
    }
};