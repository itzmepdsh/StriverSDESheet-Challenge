class Node{
    public:
        int val;
        int key;
        Node* prev;
        Node* next;
        Node(int key, int val){
            this->key = key;
            this->val = val;
            prev = NULL;
            next = NULL;
        }
};
class LRUCache {
    unordered_map<int,Node*> mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int c;

    void deleteNode(Node*& node){
        Node* temp1 = node->next;
        Node* temp2 = node->prev;
        temp2->next = temp1;
        temp1->prev = temp2;
        //delete node;
    }

    void insertAtHead(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

public:
    LRUCache(int capacity) {
        c = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())return -1;
        Node* node = mp[key];
        int res = node->val;
        deleteNode(node);
        insertAtHead(node);
        return res;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            deleteNode(mp[key]);
            Node* new_node = new Node(key,value);
            insertAtHead(new_node);
            mp[key] = new_node;
            return;
        }
        if(mp.size() == c){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* new_node = new Node(key,value);
        insertAtHead(new_node);
        mp[key] = new_node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */