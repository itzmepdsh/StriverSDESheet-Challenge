class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> row;
            row.push_back(1);
            int last = 1;
            for(int j=1;j<=i;j++){
                last = ((i-j+1)*last)/j;
                row.push_back(last);
            }
            res.push_back(row);
        }
        return res;
    }
};