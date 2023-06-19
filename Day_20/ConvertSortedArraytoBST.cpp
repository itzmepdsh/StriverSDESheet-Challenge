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
    TreeNode* buildtree(vector<int>& nums, int s, int e){
        //base case
        if(s>e)return NULL;
        //recursive case
        int mid = (s+e)>>1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildtree(nums,s,mid-1);
        root->right = buildtree(nums,mid+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0,e = nums.size()-1;
        return buildtree(nums,s,e);
    }
};