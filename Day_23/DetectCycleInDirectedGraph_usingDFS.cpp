class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(vector<int> adj[], vector<bool>& visited, vector<bool>& path_visited, int src){
        visited[src] = true;
        path_visited[src] = true;
        for(int neighbor : adj[src]){
            if(!visited[neighbor]){
                if(dfs(adj, visited, path_visited, neighbor))
                    return true;
            }
            else if(path_visited[neighbor])
                return true;
        }
        path_visited[src] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V,false), path_visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i])
                if(dfs(adj,visited,path_visited,i))
                    return true;
        }
        return false;
    }
};