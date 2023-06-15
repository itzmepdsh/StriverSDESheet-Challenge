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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL || root == p || root == q){
            return root;
        }
        //recursive case
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        //Now, we have both node from right and left. We have to decide what to return from curr node now.
        //if both left and right have null then we will return null 
        //if exactly one has non-null node then we will return that value
        //if both are non-null it means curr node is the LCA(p,q) so will return curr node 
        if(left == NULL)return right;
        if(right == NULL)return left;
        return root;
    }
};
