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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,int>> q;
        int maxi = 0;
        q.push({root,0});
        while(!q.empty()){
            int sz = q.size();
            int first,last;
            int minimal = q.front().second;
            //to strt indexing from 0 so that we can avoid overflow
            for(int i=0;i<sz;i++){
                TreeNode* frnt = q.front().first;
                int cur_idx = q.front().second;
                cur_idx = cur_idx-minimal;
                q.pop();
                if(i == 0)first = cur_idx;
                if( i == sz-1)last = cur_idx;
                if(frnt->left != NULL)q.push({frnt->left,(long long)2*cur_idx+1});
                if(frnt->right != NULL)q.push({frnt->right,(long long)2*cur_idx+2});
            }
            maxi = max(maxi,last-first+1);
        }
        return maxi;
    }
};