/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)return res;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode* frnt = q.front().first;
                int col = (q.front().second).first;
                int lvl = (q.front().second).second;
                q.pop();
                mp[col][lvl].insert(frnt->val);
                if(frnt->left)q.push({frnt->left,{col-1,lvl+1}});
                if(frnt->right)q.push({frnt->right,{col+1,lvl+1}});
            }
        }
        for(auto pr : mp){
            vector<int> vertical;
            for(auto pr2 : pr.second){
                for(int data : pr2.second){
                    vertical.push_back(data);
                }
            }
            res.push_back(vertical);
        }
        return res;
    }
};