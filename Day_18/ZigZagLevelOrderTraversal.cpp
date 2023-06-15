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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)return res;
        queue<TreeNode*> q;
        q.push(root);
        bool LeftToRight = true;
        while(!q.empty()){
            int sz = q.size();
            vector<int> lvl(sz,0);
            for(int i=0;i<sz;i++){
                TreeNode* frnt = q.front();
                q.pop();
                if(LeftToRight){
                    lvl[i] = frnt->val;
                }
                else{
                    lvl[sz-i-1] = frnt->val;
                }
                if(frnt->left)q.push(frnt->left);
                if(frnt->right)q.push(frnt->right);
            }
            LeftToRight = !LeftToRight;
            res.push_back(lvl);
        }
        return res;
    }
};