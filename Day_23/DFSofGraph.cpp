class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void traverse(vector<int> adj[], vector<bool>& visited, vector<int>& res, int i){
        res.push_back(i);
        for(int j=0;j<adj[i].size();j++){
            if(!visited[adj[i][j]]){
                visited[adj[i][j]] = true;
                traverse(adj,visited,res,adj[i][j]);
            }
        }
    }
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        vector<bool> visited(n,false);
        vector<int> res;
        visited[0] = true;
        traverse(adj,visited,res,0);
        return res;
    }
};