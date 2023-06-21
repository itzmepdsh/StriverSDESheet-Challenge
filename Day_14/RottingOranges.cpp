typedef pair<int,int> pr;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pr> q;
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> dist(m,vector<int>(n,0));
        while(!q.empty()){
            pr frnt = q.front();
            q.pop();
            int row = frnt.first;
            int col = frnt.second;
            int dx[4] = {0,0,1,-1};
            int dy[4] = {1,-1,0,0};
            for(int k=0;k<4;k++){
                int xi = row + dx[k];
                int yj = col + dy[k];
                if(xi>-1 && xi<m && yj>-1 && yj<n && grid[xi][yj] == 1){
                    grid[xi][yj] = 2;
                    dist[xi][yj] = dist[row][col]+1;
                    q.push({xi,yj});
                }
            }
        }
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)return -1;
                res = max(res,dist[i][j]);
            }
        }
        return res;
    }
};