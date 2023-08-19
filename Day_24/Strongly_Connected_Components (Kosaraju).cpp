class Solution
{
    private:
        void dfs(vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st, int node){
            visited[node] = true;
            for(auto neighbor : adj[node]){
                if(!visited[neighbor]){
                    dfs(adj,visited,st,neighbor);
                }
            }
            st.push(node);
        }
        
        void dfs2(vector<vector<int>>& adj, vector<bool>& visited, int node){
            visited[node] = true;
            for(auto neighbor : adj[node]){
                if(!visited[neighbor])
                    dfs2(adj,visited,neighbor);
            }
        }
        
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<bool> visited(V,false);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,visited,st,i);
            }
        }
        
        vector<vector<int>> adjT(V);
        for(int i=0;i<V;i++){
            visited[i] = false;
            for(int j=0;j<adj[i].size();j++){
                adjT[adj[i][j]].push_back(i);
            }
        }
        
        int cnt = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visited[node]){
                dfs2(adjT,visited,node);
                cnt++;
            }
        }
        return cnt;
    }
};