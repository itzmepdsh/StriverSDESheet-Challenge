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
    void preOrder(TreeNode* root, vector<int>& res){
        //base case
        if(root == NULL)return;
        //recursive case
        res.push_back(root->val);
        preOrder(root->left,res);
        preOrder(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        
        //Iterative Approach
        vector<int> res;
        if(root == NULL)return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* tp = st.top();
            res.push_back(tp->val);
            st.pop();
            if(tp->right != NULL)st.push(tp->right);
            if(tp->left != NULL)st.push(tp->left);
        }
        return res;

        // vector<int> res;
        // preOrder(root,res);
        // return res;
    }
};