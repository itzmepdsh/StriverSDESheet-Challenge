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
    int next(stack<TreeNode*>& nxt_st){
        TreeNode* tp = nxt_st.top();
        nxt_st.pop();
        if(tp->right){
            TreeNode* curr = tp->right;
            while(curr){
                nxt_st.push(curr);
                curr = curr->left;
            }
        }
        return tp->val;
    }
    
    int before(stack<TreeNode*>& bfr_st){
        TreeNode* tp = bfr_st.top();
        bfr_st.pop();
        if(tp->left){
            TreeNode* curr = tp->left;
            while(curr){
                bfr_st.push(curr);
                curr = curr->right;
            }
        }
        return tp->val;
    }

    bool findTarget(TreeNode* root, int target) {
        stack<TreeNode*> nxt_st;
        stack<TreeNode*> bfr_st;
        TreeNode* curr = root;
        while(curr){
            nxt_st.push(curr);
            curr = curr->left;
        }
        curr = root;
        while(curr){
            bfr_st.push(curr);
            curr = curr->right;
        }
        int nxt = next(nxt_st);
        int bfr = before(bfr_st);
        while(nxt < bfr){
            int sum = nxt+bfr;
            if(sum == target)return true;
            else if(sum < target){
                nxt = next(nxt_st);
            }
            else{
                bfr = before(bfr_st);
            }
        }
        return false;
    }
};