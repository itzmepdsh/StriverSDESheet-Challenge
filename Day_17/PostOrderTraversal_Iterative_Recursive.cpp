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
    void postOrder(TreeNode* root, vector<int>& res){
        //base case
        if(root == NULL)return;
        //recursive case
        postOrder(root->left,res);
        postOrder(root->right,res);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        //Iterative Approach (using 1 stack)
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root, *temp;
        while(curr != NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    res.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        res.push_back(temp->val);
                    }
                }
                else
                    curr = temp;
            }
        }
        return res;

        //Iterative Approach (using 2 Stacks)
        // stack<TreeNode*> st1,st2;
        // vector<int> res;
        // if(root == NULL)return res;
        // st1.push(root);
        // while(!st1.empty()){
        //     TreeNode* tp = st1.top();
        //     st1.pop();
        //     st2.push(tp);
        //     if(tp->left != NULL)st1.push(tp->left);
        //     if(tp->right != NULL)st1.push(tp->right);
        // }
        // while(!st2.empty()){
        //     res.push_back(st2.top()->val);
        //     st2.pop();
        // }
        // return res;

        //RECURSIVE APPROACH
        // vector<int> res;
        // postOrder(root,res);
        // return res;
    }
};