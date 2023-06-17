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
    TreeNode* constructTree(vector<int>& preorder, int prestrt, int preend, vector<int>& inorder, int instrt, int inend){
        //base case
        if(prestrt > preend || instrt > inend)return NULL;
        //recursive case
        TreeNode* root = new TreeNode(preorder[prestrt]);
        int inroot = instrt;
        while(inorder[inroot] != preorder[prestrt]){
            inroot++;
        }
        int x = inroot - instrt;
        root->left = constructTree(preorder,prestrt+1,prestrt+x,inorder,instrt,inroot-1);
        root->right = constructTree(preorder,prestrt+x+1,preend,inorder,inroot+1,inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return constructTree(preorder,0,preorder.size()-1,inorder, 0,inorder.size()-1);
    }
};