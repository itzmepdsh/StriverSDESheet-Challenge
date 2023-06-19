#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int x)
{
    int flor = -1;
    while(root){
        if(root->val == x)return x;
        if(root->val < x){
            flor = root->val;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return flor;
}