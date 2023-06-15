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
    pair<int,bool> chkBalanced(TreeNode* root){
        pair<int,bool> p;
        //base case
        if(root == NULL){
            p.first = 0;
            p.second = true;
            return p;
        }
        //recursive case
        pair<int,bool> pL = chkBalanced(root->left);
        pair<int,bool> pR = chkBalanced(root->right);
        p.first = max(pL.first,pR.first)+1;
        if(pL.second == true && pR.second == true)
        p.second = abs(pL.first-pR.first)<=1?true:false;
        else
        p.second = false;
        return p;
    }

    int check(TreeNode* node){
        //base case
        if(node == NULL)return 0;
        //recursive case
        int lh = check(node->left);
        if(lh == -1)return -1;
        int rh = check(node->right);
        if(rh == -1)return -1;
        if(abs(lh-rh) > 1)return -1;
        return 1+max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        
        return (check(root)!=-1);
        //return chkBalanced(root).second;
    }
};