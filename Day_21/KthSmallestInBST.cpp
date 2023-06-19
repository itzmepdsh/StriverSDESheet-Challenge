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
    void kthSmallestinBST(TreeNode* curr, int k, int& cnt, int& res){
        //base case
        if(curr == NULL)return;
        //recursive case
        kthSmallestinBST(curr->left,k,cnt,res);
        if(++cnt == k){
            res = curr->val;
            return;
        }
        kthSmallestinBST(curr->right,k,cnt,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int res = -1;
        kthSmallestinBST(root,k,cnt,res);
        return res;
    }
};