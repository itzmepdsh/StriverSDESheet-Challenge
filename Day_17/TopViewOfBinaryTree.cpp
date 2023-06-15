/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> res;
        if(root == NULL)return res;
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        while(!q.empty()){
            Node* frnt = q.front().first;
            int col = q.front().second;
            q.pop();
            if(mp.find(col) == mp.end()){
                mp[col] = frnt->data;
            }
            if(frnt->left)q.push({frnt->left,col-1});
            if(frnt->right)q.push({frnt->right,col+1});
        }
        for(auto pr : mp){
            res.push_back(pr.second);
        }
        return res;
    }
};