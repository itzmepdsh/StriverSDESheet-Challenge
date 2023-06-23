class Node{
    public:
        Node* links[2] = {NULL};
        bool isContainsKey(int idx){
            return links[idx] != NULL;
        }

        void put(int idx, Node* node){
            links[idx] = node;
        }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(int num){
            Node* curr = root;
            for(int i=31; i>=0;i--){
                int idx = (num>>i)&1;
                if(!(curr->isContainsKey(idx))){
                    curr->put(idx,new Node());
                }
                curr = curr->links[idx];
            }
        }

        int findmaxXOR(int x){
            Node* curr = root;
            int res = 0;
            for(int i=31;i>=0;i--){
                int idx = (x>>i)&1;
                if(curr->links[1-idx] != NULL){
                    res = res|(1<<i);
                    curr = curr->links[1-idx];
                }
                else{
                    curr = curr->links[idx];
                }
            }
            return res;
        }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* t = new Trie();
        for(int i=0;i<nums.size();i++){
            t->insert(nums[i]);
        }
        int res = 0;
        for(int i=0;i<nums.size();i++){
            int val = t->findmaxXOR(nums[i]);
            res = max(res,val);
        }
        return res;
    }
};