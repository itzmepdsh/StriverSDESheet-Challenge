#include<bits/stdc++.h>
class Node{
    public:
        unordered_map<char,Node*> mp;
        
        bool isContainsKey(char ch){
            return mp[ch] != NULL;
        }

        void put(char ch, Node* node){
            mp[ch] = node;
        }
};

class Trie{
    private:
        Node* root;
        int cnt = 0;
    public:
        Trie(){
            root = new Node();
        }

        void insert(string word){
            Node* curr = root;
            for(int i=0;i<word.length();i++){
                if(!(curr->isContainsKey(word[i]))){
                    cnt++;
                    curr->put(word[i],new Node());
                }
                curr = curr->mp[word[i]];
            }
        }

        int getcnt(){
            return cnt;
        }
};
int countDistinctSubstrings(string &s)
{
    //Time Complexity: O(n^2) Space Complexity: Number of distinct nodes in trie
    Trie* t = new Trie();
    for(int i=0;i<s.length();i++){
        string str = s.substr(i);
        t->insert(str);
    }
    return t->getcnt()+1;
}