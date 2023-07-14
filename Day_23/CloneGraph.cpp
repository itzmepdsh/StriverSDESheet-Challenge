/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)return NULL;
        unordered_map<Node*,Node*> mpp;
        unordered_set<Node*> visited;
        queue<Node*> q;
        q.push(node);
        visited.insert(node);
        mpp[node] = new Node(node->val);
        while(!q.empty()){
            Node* frnt = q.front();
            q.pop();
            for(auto neighbor : frnt->neighbors){
                if(!visited.count(neighbor)){
                    q.push(neighbor);
                    visited.insert(neighbor);
                    mpp[neighbor] = new Node(neighbor->val);
                }
                mpp[frnt]->neighbors.push_back(mpp[neighbor]);
            }
        }
        return mpp[node];
    }
};