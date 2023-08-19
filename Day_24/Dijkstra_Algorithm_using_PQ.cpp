class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minpq;
        vector<int> dist(V,INT_MAX);
        dist[S] = 0;
        minpq.push({0,S});
        while(!minpq.empty()){
            pair<int,int> tp = minpq.top();
            minpq.pop();
            int d = tp.first;
            int node = tp.second;
            for(auto neighbor : adj[node]){
                if(dist[neighbor[0]] > d+neighbor[1]){
                    dist[neighbor[0]] = d+neighbor[1];
                    minpq.push({d+neighbor[1],neighbor[0]});
                }
            }
        }
        return dist;
    }
};