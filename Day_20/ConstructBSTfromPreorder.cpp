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
    TreeNode* buildBST(vector<int>& preorder, int& i, int n, int ub){
        //base case
        if(i==n || preorder[i] > ub)return NULL;
        //recursive case
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = buildBST(preorder,i,n,root->val);
        root->right = buildBST(preorder,i,n,ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        int n = preorder.size();
        return buildBST(preorder,i,n,INT_MAX);
    }
};