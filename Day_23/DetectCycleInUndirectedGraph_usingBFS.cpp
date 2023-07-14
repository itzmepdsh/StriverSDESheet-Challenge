class Solution {
  private:
  
    bool chkCycle(vector<int> adj[], vector<bool>& visited, int src){
        queue<pair<int,int>>q;
        q.push({src,-1});
        visited[src] = true;
        while(!q.empty()){
            int cur_node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int i=0;i<adj[cur_node].size();i++){
                if(adj[cur_node][i] != parent && visited[adj[cur_node][i]])return true;
                if(adj[cur_node][i] != parent){
                    visited[adj[cur_node][i]] = true;
                    q.push({adj[cur_node][i],cur_node});
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(chkCycle(adj,visited,i))return true;
            }
        }
        return false;
    }
};