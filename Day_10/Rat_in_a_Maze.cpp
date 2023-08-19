// User function template for C++

class Solution{
    public:
    void generatePath(vector<vector<int>> &m, int n,vector<string>& res, string path, int i, int j){
        //base case
        if(i==n-1 && j==n-1){
            if(m[i][j] == 0)return;
            res.push_back(path);
            return;
        }
        if(i==-1 || j==-1 || i==n || j==n || m[i][j] == 0)return;
        //recursive case
        m[i][j] = 0;
        generatePath(m,n,res,path+'U',i-1,j);
        generatePath(m,n,res,path+'L',i,j-1);
        generatePath(m,n,res,path+'R',i,j+1);
        generatePath(m,n,res,path+'D',i+1,j);
        m[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        string path = "";
        generatePath(m,n,res,path,0,0);
        return res;
    }
};

    