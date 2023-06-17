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
    TreeNode* constructTree(vector<int> inorder, int instrt, int inend, vector<int> postorder, int poststrt, int postend){
        //base case
        if(instrt > inend || poststrt > postend)return NULL;
        //recursive case
        TreeNode* root = new TreeNode(postorder[postend]);
        int root_idx = instrt;
        while(inorder[root_idx] != root->val)root_idx++;
        int x = inend-root_idx;
        root->left = constructTree(inorder,instrt,root_idx-1,postorder,poststrt,postend-x-1);
        root->right = constructTree(inorder,root_idx+1,inend,postorder,postend-x,postend-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int insz = inorder.size(),postsz = postorder.size();
        return constructTree(inorder,0,insz-1,postorder,0,postsz-1);
    }
};