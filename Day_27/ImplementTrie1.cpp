class Node{
    private:
        unordered_map<char,Node*> mp;
        bool flag = false;

    public:
        bool containsKey(char ch){
            return mp[ch] != NULL;
        }

        void put(char ch, Node* node){
            mp[ch] = node;
        }

        void end(){
            flag = true;
        }

        bool isEnd(){
            return flag;
        }

        Node* next(char ch){
            return mp[ch];
        }
};
class Trie {
    private:
        Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {//O(n)
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(!curr->containsKey(word[i])){
                curr->put(word[i],new Node());
            }
            curr = curr->next(word[i]);
        }
        curr->end();
    }
    
    bool search(string word) {//O(n)
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(!(curr->containsKey(word[i])))return false;
            curr = curr->next(word[i]);
        }
        return curr->isEnd();
    }
    
    bool startsWith(string prefix) {//O(n)
        Node* curr = root;
        for(int i=0;i<prefix.length();i++){
            if(!(curr->containsKey(prefix[i])))return false;
            curr = curr->next(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */