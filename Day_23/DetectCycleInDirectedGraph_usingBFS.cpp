class Solution {
  public:
    // Function to detect cycle in a directed graph.

    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indeg(V,0);
        for(int i=0;i<V;i++){
            for(int it : adj[i]){
                indeg[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i] == 0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int frnt = q.front();
            q.pop();
            topo.push_back(frnt);
            for(int it : adj[frnt]){
                if(--indeg[it] == 0)
                    q.push(it);
            }
        }
        return topo.size() != V;
    }
};