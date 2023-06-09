class Solution {
public:
    void makecombination(vector<int> can, int n, int target, vector<vector<int>>& res, vector<int> out, int sum, int i){
        if(sum == target){
            res.push_back(out);
            return;
        }
        if(sum > target)return;
        for(int idx = i;idx < n;idx++){
            out.push_back(can[idx]);
            makecombination(can,n,target,res,out,sum+can[idx],idx);
            out.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        int n = cand.size();
        vector<vector<int>> res;
        vector<int> out;
        makecombination(cand,n,target,res,out,0,0);
        return res;
    }
};