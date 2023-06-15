/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
void traverse(Node* root, int level, vector<int>& res){
    //base case
    if(root == NULL)return;
    //recursive case
    if(res.size() == level)res.push_back(root->data);
    traverse(root->left,level+1,res);
    traverse(root->right,level+1,res);
    
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res;
   if(root == NULL)return res;
   traverse(root,0,res);
   return res;
}