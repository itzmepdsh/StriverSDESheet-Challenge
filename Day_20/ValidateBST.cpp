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
#define ll long long
class Solution {
public:
    ll findmaximum(TreeNode* root){
        if(root == NULL)return (ll)INT_MIN-1;
        while(root->right){
            root = root->right;
        }
        return (ll)root->val;
    }
    ll findminimum(TreeNode* root){
        if(root == NULL)return (ll)INT_MAX+1;
        while(root->left){
            root = root->left;
        }
        return (ll)root->val;
    }

    bool isValid(TreeNode* root, ll minval, ll maxval){
        //base case
        if(root == NULL)return true;
        //recursive case
        if(root->val <= minval || root->val >= maxval)return false;
        return isValid(root->left,minval,root->val) && isValid(root->right,root->val,maxval);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValid(root,(ll)INT_MIN-1,(ll)INT_MAX+1);

        // //base case
        // if(root == NULL)return true;
        // //recursive case
        // ll LSTmax = findmaximum(root->left);
        // ll RSTmin = findminimum(root->right);
        // if(root->val <= LSTmax || root->val >= RSTmin)return false;
        // return isValidBST(root->left) && isValidBST(root->right);
    }
};