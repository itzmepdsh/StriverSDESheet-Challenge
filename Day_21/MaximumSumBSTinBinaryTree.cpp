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

class triplet{
    public:
        int maxi;
        int mini;
        int sum;
        triplet(int maxi, int mini,int sum){
            this->maxi = maxi;
            this->mini = mini;
            this->sum = 0;
        }
};
class Solution {
public:
    triplet postorder(TreeNode* root){
        //base case
        if(root == NULL){
            return triplet(INT_MIN,INT_MAX,0);
        }

        //recursive case
        triplet left_t = postorder(root->left);
        triplet right_t = postorder(root->right);
        triplet t(0,0,0);
        if(root->val > left_t.maxi && root->val < right_t.mini){
            t.sum = root->val + left_t.sum + right_t.sum;
            t.maxi = max(root->val,max(left_t.maxi,right_t.maxi));
            t.mini = min(root->val,min(left_t.mini,right_t.mini));
        }
        else
        t = triplet(INT_MAX,INT_MIN,max(left_t.sum,right_t.sum));
        res = max(res,t.sum);
        return t;
    }

    int res = INT_MIN;
    int maxSumBST(TreeNode* root) {
        triplet t = postorder(root);
        if(res<0)return 0;
        return res;
    }
};