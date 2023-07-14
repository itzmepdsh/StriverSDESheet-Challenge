class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfs(vector<int> adj[], vector<bool>& visited, int src, int parent){
        visited[src] = true;
        for(int i=0;i<adj[src].size();i++){
            if(!visited[adj[src][i]]){
                if(dfs(adj,visited,adj[src][i],src))
                    return true;
            }
            else if(adj[src][i] != parent)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(adj,visited,i,-1))
                    return true;
            }
        }
        return false;
    }
};