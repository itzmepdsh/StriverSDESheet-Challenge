typedef pair<int,int> pr;
class myComp{
    public:
        bool operator()(pr& a, pr& b){
            return a.first < b.first;
        }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //Monotonic Queue T.C. = O(N)
        deque<int> q;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            while(!q.empty() && nums[q.back()] <= nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            if(q.front() <= i-k)q.pop_front();
            if(i>=k-1)res.push_back(nums[q.front()]);
        }
        return res;

        // using PQ T.C. O(Nlogk)
        // int n = nums.size();
        // int i=0,j=0;
        // vector<int> res;
        // priority_queue<pr,vector<pr>,myComp> pq;
        // while(j<n){
        //     pq.push({nums[j],j});
        //     if(j-i+1 < k){
        //         j++;
        //     }
        //     else if(j-i+1 == k){
        //         while(pq.top().second < i)pq.pop();
        //         res.push_back(pq.top().first);
        //         j++;
        //         i++;
        //     }
        // }
        // return res;
    }
};