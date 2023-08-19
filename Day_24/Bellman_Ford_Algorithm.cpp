// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V,1e8);
        dist[S] = 0;
        for(int i=0;i<V-1;i++){
            for(auto edge : edges){
                if(dist[edge[0]] != 1e8 && dist[edge[0]]+edge[2] < dist[edge[1]]){
                    dist[edge[1]] = dist[edge[0]]+edge[2];
                }
            }
        }
        
        for(auto edge : edges){
            if(dist[edge[0]] != 1e8 && dist[edge[0]]+edge[2] < dist[edge[1]]){
                    return {-1};
                }
        }
        
        return dist;
    }
};