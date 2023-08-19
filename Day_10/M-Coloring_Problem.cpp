class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool solve(vector<vector<int>>& adjList, int m, int n, vector<int>& color,int node){
        //base case
        if(node == n)
            return true;
        //recursive case
        int sz = adjList[node].size();
        for(int c=1;c<=m;c++){
            int i=0;
            for(;i<sz;i++){
                if(color[adjList[node][i]] == c)break;
            }
            if(i==sz){
                color[node] = c;
                if(solve(adjList,m,n,color,node+1))
                    return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<vector<int>> adjList(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]){
                    adjList[i].push_back(j);
                }
            }
        }
        vector<int> color(n,0);
        return solve(adjList,m,n,color,0);
    }
};