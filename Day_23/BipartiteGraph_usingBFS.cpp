class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<int>& visited, int src){
        queue<int> q;
        q.push(src);
        visited[src] = 0;
        while(!q.empty()){
            int frnt = q.front();
            q.pop();
            for(int adj : graph[frnt]){
                if(visited[adj] == -1){
                    q.push(adj);
                    visited[adj] = 1-visited[frnt];
                }
                else if(visited[adj] == visited[frnt])
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i] == -1)
                if(!bfs(graph, visited, i))
                    return false;
        }
        return true;
    }
};