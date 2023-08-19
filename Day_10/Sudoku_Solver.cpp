class Solution {
public:
    bool canPlace(vector<vector<char>>& grid, int n, int r, int c, char dig){
        for(int i=0;i<n;i++){
            if(grid[i][c] == dig)return false;
        }
        for(int j=0;j<n;j++){
            if(grid[r][j] == dig)return false;
        }
        int root_n = sqrt(n);
        int strt_i = (r/root_n)*root_n;
        int strt_j = (c/root_n)*root_n;
        for(int i=strt_i;i<strt_i+root_n;i++){
            for(int j=strt_j;j<strt_j+root_n;j++){
                if(grid[i][j] == dig)return false;
            }
        }
        return true;
    }

    bool Sudoku(vector<vector<char>>& grid, int n, int i, int j){
        //base case
        if(i==n){
            return true;
        }
        //recursive case
        if(j==n){
            return Sudoku(grid,n,i+1,0);
        }
        if(grid[i][j] != '.'){
            return Sudoku(grid,n,i,j+1);
        }
        for(char k='1';k<='9';k++){
            if(canPlace(grid,n,i,j,k)){
                grid[i][j] = k;
                if(Sudoku(grid,n,i,j+1))return true;
                grid[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        Sudoku(board,n,0,0);
    }
};