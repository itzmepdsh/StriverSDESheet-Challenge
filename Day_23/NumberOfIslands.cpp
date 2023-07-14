class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int m ,int n, int i, int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = true;
        while(!q.empty()){
            pair<int,int> frnt = q.front();
            q.pop();
            int x = frnt.first, y = frnt.second;
            int dx[4] = {-1,0,0,1};
            int dy[4] = {0,-1,1,0};
            for(int k=0;k<4;k++){
                int a = x+dx[k], b = y+dy[k];
                if(a==-1 || b==-1 || a==m || b==n || grid[a][b] == '0' || visited[a][b])continue;
                q.push({a,b});
                visited[a][b] = true;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int islands = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    bfs(grid,visited,m,n,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};