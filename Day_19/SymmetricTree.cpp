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
    bool is_mirrored(TreeNode* left_tree, TreeNode* right_tree){
        if(left_tree == NULL && right_tree == NULL)return true;
        if(left_tree == NULL || right_tree == NULL)return false;
        if(left_tree->val != right_tree->val) return false;
        return is_mirrored(left_tree->left,right_tree->right) && is_mirrored(left_tree->right, right_tree->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)return true;
        return is_mirrored(root->left,root->right);
    }
};