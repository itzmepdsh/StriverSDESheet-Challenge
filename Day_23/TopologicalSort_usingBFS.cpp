class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegrees(V,0);
	    for(int i=0;i<V;i++){
	        for(int neigh : adj[i]){
	            indegrees[neigh]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegrees[i] == 0)
	            q.push(i);
	    }
	    
	    vector<int> res;
	    while(!q.empty()){
	        int frnt = q.front();
	        res.push_back(frnt);
	        q.pop();
	        for(int neighbor : adj[frnt]){
	            indegrees[neighbor]--;
	            if(indegrees[neighbor] == 0)
	                q.push(neighbor);
	        }
	    }
	    
	    return res;
	}
};