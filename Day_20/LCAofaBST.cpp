/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        //base case
        if(root->val == p->val || root->val == q->val)return root;
        if(root->val > p->val && root->val < q->val)return root;
        //recursive case
        if(root->val > p->val && root->val > q->val)
            return findLCA(root->left,p,q);
        else if(root->val < p->val && root->val < q->val)
            return findLCA(root->right,p,q);
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val){
            return findLCA(root,q,p);
        }
        return findLCA(root,p,q);
    }
};