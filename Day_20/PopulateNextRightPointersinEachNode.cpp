/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || root->left == NULL)return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                Node* frnt = q.front();
                q.pop();
                if(i!=sz-1){
                    frnt->next = q.front();
                }
                if(frnt->left)q.push(frnt->left);
                if(frnt->right)q.push(frnt->right);
            }
        }
        return root;
    }
};