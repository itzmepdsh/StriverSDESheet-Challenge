#include <bits/stdc++.h> 
class Node{
    public:
        unordered_map<char,Node*> mp;
        int ew = 0;
        int cp = 0;

        bool containsKey(char ch){
            return mp[ch] != NULL;
        }

        void put(char ch, Node* node){
            mp[ch] = node;
        }
};
class Trie{
    Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(!(curr->containsKey(word[i]))){
                curr->put(word[i],new Node());
                curr = curr->mp[word[i]];
                curr->cp = 1;
            }
            else{
                curr = curr->mp[word[i]];
                curr->cp = curr->cp + 1;
            }
        }
        curr->ew = (curr->ew) + 1;
    }

    int countWordsEqualTo(string &word){
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(!(curr->containsKey(word[i]))){
                return 0;
            }
            curr = curr->mp[word[i]];
        }
        return curr->ew;
    }

    int countWordsStartingWith(string &word){
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            if(!(curr->containsKey(word[i]))){
                return 0;
            }
            curr = curr->mp[word[i]];
        }
        return curr->cp;
    }

    void erase(string &word){
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            curr = curr->mp[word[i]];
            curr->cp = (curr->cp)-1;
        }
        curr->ew = (curr->ew)-1;
    }
};
