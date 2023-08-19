class DisjointSet{
    unordered_map<int,int> parent;
    unordered_map<int,int> size;
    public:
        void createSet(int x){
            parent[x] = x;
            size[x] = 1;
        }
        
        int find(int x){
            if(parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        }
        
        void unionSet(int x, int y){
            int lx = find(x);
            int ly = find(y);
            if(lx != ly){
                if(size[lx] < size[ly]){
                    parent[lx] = ly;
                    size[ly] += size[lx];
                }
                else{
                    parent[ly] = lx;
                    size[lx] += size[ly];
                }
            }
        }
};

typedef pair<int,pair<int,int>> pr;
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        DisjointSet ds;
        for(int i=0;i<V;i++){
            ds.createSet(i);
        }
        vector<pr> edgeList;
        for(int i=0;i<V;i++){
            for(auto edge : adj[i]){
                if(edge[0] < i)continue;
                edgeList.push_back({edge[1],{i,edge[0]}});
            }
        }
        sort(edgeList.begin(),edgeList.end());
        int cnt = 0;
        int sum =0;
        int i=0;
        while(cnt < V-1){
            int u = edgeList[i].second.first;
            int v = edgeList[i].second.second;
            if(ds.find(u) == ds.find(v)){
                i++;
                continue;
            }
            ds.unionSet(u,v);
            cnt++;
            sum += edgeList[i].first;
            i++;
        }
        return sum;
    }
};