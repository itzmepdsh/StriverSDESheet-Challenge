class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(vector<int> adj[], vector<bool>& visited, stack<int>& st, int src){
	    visited[src] = true;
	    for(int neighbor : adj[src]){
	        if(!visited[neighbor])
	            dfs(adj,visited,st,neighbor);
	    }
	    st.push(src);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V,false);
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(!visited[i])
	            dfs(adj,visited,st,i);
	    }
	    vector<int> res;
	    while(!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
	}
};