class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> minpq;
        for(int i=0;i<k;i++){
            minpq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            minpq.push(nums[i]);
            minpq.pop();
        }
        return minpq.top();
    }
};