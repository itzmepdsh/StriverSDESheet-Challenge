/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root == NULL){
            s = "#";
            return s;
        }
        queue<TreeNode*> q;
        q.push(root);
        s += to_string(root->val);
        s += ',';
        while(!q.empty()){
            TreeNode* frnt = q.front();
            q.pop();
            if(frnt->left){
                q.push(frnt->left);
                s += to_string(frnt->left->val);
            }
            else{
                s += '#';
            }
            s += ',';
            if(frnt->right){
                q.push(frnt->right);
                s += to_string(frnt->right->val);
            }
            else{
                s += '#';
            }
            s += ',';
        }
        s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        if(data == "#")return NULL;
        queue<TreeNode*> q;
        int i=0;
        string temp = "";
        while(i<n && data[i] != ','){
            temp += data[i];
            i++;
        }
        i++;
        TreeNode* root = new TreeNode(stoi(temp));
        q.push(root);
        while(!q.empty()){
            string templ = "", tempr = "";
            while(i<n && data[i] != ','){
                templ += data[i];
                i++;
            }
            i++;
            while(i<n && data[i] != ','){
                tempr += data[i];
                i++;
            }
            i++;
            TreeNode* parent = q.front();
            q.pop();
            if(templ == "#")parent->left = NULL;
            else{
                int value = stoi(templ);
                TreeNode* left_child = new TreeNode(value);
                parent->left = left_child;
                q.push(left_child);
            }
            if(tempr == "#")parent->right = NULL;
            else{
                int value = stoi(tempr);
                TreeNode* right_child = new TreeNode(value);
                parent->right = right_child;
                q.push(right_child);
            }
        }
        return root;
    }
};