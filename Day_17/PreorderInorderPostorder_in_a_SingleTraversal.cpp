#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#define pr pair<BinaryTreeNode<int>*,int> 
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int> inorder,preorder,postorder;
    stack <pr> st;
    st.push({root,1});
    if(root == NULL)return{{},{},{}};
    while(!st.empty()){
        pr t = st.top();
        st.pop();
        if(t.second == 1){
            preorder.push_back(t.first->data);
            st.push({t.first,t.second+1});
            if(t.first->left != NULL)
              st.push({t.first->left, 1});
        }
        else if(t.second == 2){
            inorder.push_back(t.first->data);
            st.push({t.first,t.second+1});
            if(t.first->right != NULL)
                st.push({t.first->right,1});
        }
        else{
            postorder.push_back(t.first->data);
        }
    }
    vector<vector<int>> res;
    res.push_back(inorder);
    res.push_back(preorder);
    res.push_back(postorder);
    return res;
}