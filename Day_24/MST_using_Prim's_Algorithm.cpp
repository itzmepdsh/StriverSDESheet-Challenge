class Solution
{
    typedef pair<int,pair<int,int>> pr;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adjList[])
    {
        int sum = 0;
        vector<bool> visited(n,false);
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        vector<vector<int>> edgesofMST;
        pq.push({0,{0,-1}});
        while(!pq.empty()){
            pr frnt = pq.top();
            pq.pop();
            int wt = frnt.first;
            int node = frnt.second.first;
            int parent = frnt.second.second;
            if(visited[node])continue;
            if(parent != -1){
                sum += wt;
                edgesofMST.push_back({parent,node});
            }
            visited[node] = true;
            for(auto neighbor : adjList[node]){
                if(!visited[neighbor[0]]){
                    pq.push({neighbor[1],{neighbor[0],node}});
                }
            }
            
        }
        return sum;
    }
};