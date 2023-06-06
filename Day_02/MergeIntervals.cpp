class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int i =0;
        while(i<n){
            vector<int> pr(2);
            pr[0] = intervals[i][0];
            pr[1] = intervals[i][1];
            while(i<n-1 && intervals[i+1][0]<=pr[1]){
                pr[1] = max(pr[1],intervals[i+1][1]);
                i++;
            }
            res.push_back(pr);
            i++;
        }
        return res;
    }
};