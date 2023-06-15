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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(!root)return res;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> lvl;
            while(sz--){
                TreeNode* frnt = q.front();
                q.pop();
                lvl.push_back(frnt->val);
                if(frnt->left != NULL)q.push(frnt->left);
                if(frnt->right != NULL)q.push(frnt->right);
            }
            res.push_back(lvl);
        }
        return res;
    }
};