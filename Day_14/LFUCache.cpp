class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        int uc;
        Node(int key, int val){
            this->key = key;
            this->val = val;
            next = NULL;
            prev = NULL;
            uc = 1;
        }
};

class List{
    public:
        int sz;
        Node* head;
        Node* tail;
        List(){
            head = new Node(-1,-1);
            tail = new Node(-1,-1);
            head->next = tail;
            tail->prev = head;
            sz = 0;
        }

        void insertAtHead(Node* newNode){
            Node* temp = head->next;
            head->next = newNode;
            newNode->prev = head;
            newNode->next = temp;
            temp->prev = newNode;
            sz++;
        }

        void deleteNode(Node* node){
            Node* delnodeprev = node->prev;
            Node* delnodenext = node->next;
            delnodeprev->next = delnodenext;
            delnodenext->prev = delnodeprev;
            sz--;
        }
};

class LFUCache {
    map<int,Node*> keynode;
    map<int,List*> freqlist;
    int c;
    int minfreq;
    int cursz;
    
public:
    LFUCache(int c) {
        this->c = c;
        cursz = 0;
        minfreq = 0;
    }
    
    void update(Node *node) {
        keynode.erase(node->key); 
        freqlist[node->uc]->deleteNode(node); 
        if(node->uc == minfreq && freqlist[node->uc]->sz == 0) {
            minfreq++; 
        }
        
        List* nextHigherFreqList = new List();
        if(freqlist.find(node->uc + 1) != freqlist.end()) {
            nextHigherFreqList = freqlist[node->uc + 1];
        } 
        node->uc += 1; 
        nextHigherFreqList->insertAtHead(node); 
        freqlist[node->uc] = nextHigherFreqList; 
        keynode[node->key] = node;
    }

    int get(int key) {
        if(keynode.find(key) == keynode.end())return -1;
        Node* node = keynode[key];
        int res = node->val;
        update(node);
        return res;
    }
    
    void put(int key, int value) {
        if(keynode.find(key) != keynode.end()){
            Node* node = keynode[key];
            node->val = value;
            update(node);
            return;
        }

        if(cursz == c){
            List* list = freqlist[minfreq];
            keynode.erase(list->tail->prev->key);
            list->deleteNode(list->tail->prev);
            cursz--;
        }
        cursz++;
        minfreq = 1;
        Node* newNode = new Node(key,value);
        keynode[key] = newNode;
        if(freqlist.find(minfreq) == freqlist.end()){
            List* list = new List();
            list->insertAtHead(newNode);
            freqlist[minfreq] = list;
        }
        else{
            List* list = freqlist[minfreq];
            list->insertAtHead(newNode);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */