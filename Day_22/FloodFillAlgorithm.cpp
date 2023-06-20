typedef pair<int,int> pr;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pr> q;
        q.push({sr,sc});
        visited[sr][sc] = true;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                pr frnt = q.front();
                int row = frnt.first;
                int col = frnt.second;
                q.pop();
                int dx[4] = {0,0,-1,1};
                int dy[4] = {-1,1,0,0};
                for(int k=0;k<4;k++){
                    int cr = row+dx[k];
                    int cc = col+dy[k];
                    if(cr == -1 || cr == m || cc == -1 || cc == n)
                        continue;
                    if(!visited[cr][cc] && image[cr][cc] == image[row][col]){
                        q.push({cr,cc});
                        visited[cr][cc] = true;
                    }
                }
                image[row][col] = color;
            }
        }
        return image;
    }
};