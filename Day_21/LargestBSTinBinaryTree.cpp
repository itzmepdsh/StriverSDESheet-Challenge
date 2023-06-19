/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class triplet{
    public:
        int sz;
        int maxi;
        int mini;
        triplet(int sz, int maxi, int mini){
            this->sz = sz;
            this->maxi = maxi;
            this->mini = mini;
        }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    triplet postorder(Node* root){
        //base case
        if(root == NULL){
            triplet t(0,INT_MIN,INT_MAX);
            return t;
        }
        if(root->left == NULL && root->right == NULL){
            triplet t(1,root->data,root->data);
            return t;
        }
        //recursive case
        triplet Left_t = postorder(root->left);
        triplet Right_t = postorder(root->right);
        if(root->data > Left_t.maxi && root->data < Right_t.mini){
            int size = Left_t.sz+Right_t.sz+1;
            int maximum = max(Right_t.maxi,root->data);
            int minimum = min(Left_t.mini,root->data);
            triplet t(size,maximum,minimum);
            return t;
        }
        triplet t(max(Left_t.sz,Right_t.sz),INT_MAX,INT_MIN);
        return t;
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	return postorder(root).sz;
    }
};