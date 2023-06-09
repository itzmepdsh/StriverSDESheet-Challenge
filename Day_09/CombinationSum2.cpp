class Solution {
public:
    void makecombinations(vector<int> cand, int n, int target, vector<vector<int>>& res, vector<int> out, int sum, int idx){
        //base case
        if(sum == target){
            res.push_back(out);
            return;
        }
        if(sum > target)return;
        //recursive case
        for(int i=idx;i<n;i++){
            if(i!=idx && cand[i] == cand[i-1])continue;
            out.push_back(cand[i]);
            makecombinations(cand,n,target,res,out,sum+cand[i],i+1);
            out.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        int n = cand.size();
        sort(cand.begin(),cand.end());
        vector<vector<int>> res;
        vector<int> out;
        makecombinations(cand,n,target,res,out,0,0);
        return res;
    }
};