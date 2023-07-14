class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<bool> visited(V,false);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int frnt = q.front();
            if(!visited[frnt])
                res.push_back(frnt);
            visited[frnt] = true;
            q.pop();
            vector<int> neighborList = adj[frnt];
            for(int neighbor : neighborList){
                if(!visited[neighbor])
                    q.push(neighbor);
            }
        }
        return res;
    }
};