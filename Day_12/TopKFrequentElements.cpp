typedef pair<int,int> pr;
class myComp{
    public:
        bool operator()(pr a, pr b){
            if(a.second > b.second)return true;
            return false;
        }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        priority_queue<pr,vector<pr>,myComp> minpq;
        for(auto paired : mp){
            minpq.push(paired);
            if(minpq.size() > k)minpq.pop();
        }
        vector<int> res;
        while(!minpq.empty()){
            res.push_back(minpq.top().first);
            minpq.pop();
        }
        return res;
    }
};