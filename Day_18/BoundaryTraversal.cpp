/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void leftBoundary(Node* root, vector<int>& res){
        Node* curr = root->left;
        while(curr != NULL){
            if(curr->left != NULL || curr->right != NULL)res.push_back(curr->data);
            if(curr->left != NULL)curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void rightBoundary(Node* root, vector<int>& res){
        Node* curr = root->right;
        stack<int> st;
        while(curr != NULL){
            if(curr->left != NULL || curr->right != NULL)st.push(curr->data);
            if(curr->right != NULL)curr = curr->right;
            else curr = curr->left;
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
    }
    
    void addleaves(Node* root, vector<int>& res){//Inorder Traversal
        //base case
        if(root->left == NULL && root->right == NULL){
            res.push_back(root->data);
            return;
        }
        //recurisve case
        if(root->left)addleaves(root->left,res);
        if(root->right)addleaves(root->right,res);
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> res;
        if(root == NULL)return res;
        if(root->left != NULL || root->right != NULL)res.push_back(root->data);
        leftBoundary(root,res);
        addleaves(root,res);
        rightBoundary(root,res);
        return res;
    }
};