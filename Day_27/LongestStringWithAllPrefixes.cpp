#include <bits/stdc++.h> 

class Node{
    public:
     map<char,Node*> mp;
     bool flag = false;

     bool containsKey(char ch){
         return mp[ch] != NULL;
     }

     void put(char ch, Node* newNode){
         mp[ch] = newNode;
     }

     void isEnd(){
         flag = true;
     }
};

class trie{
    private:
        Node* root;
    public:
        trie(){
            root = new Node();
        }

        void insert(string word){
            Node* curr = root;
            for(int i=0;i<word.length();i++){
                if(!(curr->containsKey(word[i]))){
                    Node* newNode = new Node();
                    curr->put(word[i],newNode);
                }
                curr = curr->mp[word[i]];
            }
            curr->isEnd();
        }
        
        bool isCompstr(string word){
            Node* curr = root;
            for(int i=0;i<word.length();i++){
                if(curr->mp[word[i]]->flag == false)
                    return false;
                curr = curr->mp[word[i]];
            }
            return true;
        }       
};

string completeString(int n, vector<string> &a){
    trie* t = new trie();
    for(int i=0;i<n;i++){
        t->insert(a[i]);
    }
    string res = "";
    for(int i=0;i<n;i++){
        if(t->isCompstr(a[i])){
          if (res.length() <= a[i].length()) {
            if(res.length() == a[i].length())res = res<a[i]?res:a[i];
            else res = a[i];
          }
        }
    }
    if(res == "")return "None";
    return res;
}