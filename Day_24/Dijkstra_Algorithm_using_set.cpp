class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> st;
        dist[S] = 0;
        st.insert({0,S});
        while(!st.empty()){
            pair<int,int> pr = *st.begin();
            st.erase(pr);
            int d = pr.first;
            int node = pr.second;
            for(auto neighbor : adj[node]){
                if(d+neighbor[1] < dist[neighbor[0]]){
                    if(dist[neighbor[0]] != INT_MAX)st.erase({dist[neighbor[0]],neighbor[0]});
                    dist[neighbor[0]] = d+neighbor[1];
                    st.insert({dist[neighbor[0]],neighbor[0]});
                }
            }
        }
        return dist;
    }
};