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

        int mapsz(){
            return mp.size();
        }

        pair<char,Node*> nextchar(){
            for(auto pr : mp){
                if(isEnd())return {'#',NULL};
                return pr;
            }
            return {'#',NULL};
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

    string longestprefix(){
        Node* curr = root;
        string str = "";
        while(curr){
            if(curr->mapsz() > 1)return str;
            pair<char,Node*> ext = curr->nextchar();
            if(ext.first == '#')return str;
            str += ext.first;
            curr = ext.second;
        }
        return str;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t = new Trie();
        for(int i=0;i<strs.size();i++){
            if(strs[i].length() == 0)return "";
            t->insert(strs[i]);
        }
        return t->longestprefix();


        // int rows = strs.size();
        // string res = "";
        // for(int j=0;j<strs[0].length();j++){
        //     for(int i=0;i<rows;i++){
        //         if(strs[i][j] != strs[0][j])return res;
        //     }
        //     res += strs[0][j];
        // }
        // return res;
    }
};