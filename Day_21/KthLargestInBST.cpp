/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    
    void findkth(Node* root, int& k, int& res){
        //base case
        if(root == NULL)return;
        //recursive case
        findkth(root->right,k,res);
        if(--k==0){
            res = root->data;
            return;
        }
        findkth(root->left,k,res);
    }
    int kthLargest(Node *root, int k)
    {
        //Your code here
        int res;
        findkth(root,k,res);
        return res;
    }
};