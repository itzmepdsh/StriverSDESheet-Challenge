class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> res;
        if(!root)return res;
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        while(!q.empty()){
            Node* frnt = q.front().first;
            int col = q.front().second;
            q.pop();
            mp[col] = frnt->data;
            if(frnt->left)q.push({frnt->left,col-1});
            if(frnt->right)q.push({frnt->right,col+1});
        }
        for(auto pr : mp){
            res.push_back(pr.second);
        }
        return res;
    }
};