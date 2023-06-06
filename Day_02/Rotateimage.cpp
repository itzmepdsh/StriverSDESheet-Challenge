class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int j=0;j<n;j++){
            int is=0,ie=m-1;
            while(is<ie){
                swap(matrix[is][j],matrix[ie][j]);
                is++;
                ie--;
            }
        }
        for(int i=0;i<m-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};