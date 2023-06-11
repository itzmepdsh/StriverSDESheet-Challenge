/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node* temp = head;
        while(temp != NULL){
            Node* n = new Node(temp->val);
            mp[temp] = n;
            temp = temp->next;
        }
        Node* newHead = mp[head];
        Node* temp2 = head;
        while(temp2 != NULL){
            Node* curr = mp[temp2];
            curr->next = (temp2->next == NULL)?NULL:mp[temp2->next];
            curr->random = (temp2->random == NULL)?NULL:mp[temp2->random];
            temp2 = temp2->next;
        }
        return newHead;
    }
};