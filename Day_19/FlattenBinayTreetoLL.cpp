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
    void flatten(TreeNode* root) {
        //base case
        if(root == NULL)return;
        //recursive case
        flatten(root->left);
        flatten(root->right);
        TreeNode* LSTroot = root->left;
        TreeNode* RSTroot = root->right;
        if(LSTroot == NULL) return;
        TreeNode* curr = LSTroot;
        while(curr->right != NULL){
            curr = curr->right;
        }
        root->left = NULL;
        root->right = LSTroot;
        curr->right = RSTroot;
    }
};