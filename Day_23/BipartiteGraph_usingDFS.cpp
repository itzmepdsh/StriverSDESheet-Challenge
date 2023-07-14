class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int src, int color){
        visited[src] = color;
        for(int adj : graph[src]){
            if(visited[adj] == -1){
                if(!dfs(graph, visited, adj, 1-color))
                    return false;
            }
            else if(visited[adj] == visited[src]){
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
                if(!dfs(graph, visited, i,0))
                    return false;
        }
        return true;
    }
};