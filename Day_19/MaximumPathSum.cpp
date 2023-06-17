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
    int maxPath(TreeNode* root, int& maxi){
        //base case
        if(root == NULL)return 0;
        //recursive case
        int leftsum = max(0,maxPath(root->left,maxi));
        int rightsum = max(0,maxPath(root->right,maxi));
        maxi = max(maxi,root->val+leftsum+rightsum);
        return root->val + max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root,maxi);
        return maxi;
    }
};