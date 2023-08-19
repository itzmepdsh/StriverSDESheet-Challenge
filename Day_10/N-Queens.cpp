class Solution {
public:
    void findnQueensPos(int r, int n, vector<vector<string>>& res, vector<int>& qpos){
        //base case
        if(r==n){
            vector<string> board;
            for(int i=0;i<n;i++){
                string row = "";
                for(int j=0;j<n;j++){
                    if(qpos[i]==j)row += 'Q';
                    else row += '.';
                }
                board.push_back(row);
            }
            res.push_back(board);
            return;
        }
        //recursive case
        for(int j=0;j<n;j++){
            int i=0;
            for(;i<=r-1;i++){
                if(qpos[i] == j || qpos[i]+i == j+r || qpos[i]-i == j-r){
                    break;
                }
            }
            if(i==r){
                qpos[r] = j;
                findnQueensPos(r+1,n,res,qpos);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> qpos(n,-1);
        findnQueensPos(0,n,res,qpos);
        return res;
    }
};