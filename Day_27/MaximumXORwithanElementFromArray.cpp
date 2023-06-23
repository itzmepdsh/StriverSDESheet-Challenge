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

typedef pair<int,pair<int,int>> pr;
bool myComp(pr a ,pr b){
    return a.second.second < b.second.second;
}

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie* t = new Trie();
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int q = queries.size();
        vector<int> res(q,-1);
        vector<pr> quer;
        for(int i=0;i<q;i++){
            quer.push_back({i,{queries[i][0],queries[i][1]}});
        }
        sort(quer.begin(),quer.end(),myComp);
        int i = 0;
        for(int j=0;j<q;j++){
            while(i<n && nums[i] <= quer[j].second.second){
                t->insert(nums[i]);
                i++;
            }
            if(i != 0){
                res[quer[j].first] = t->findmaxXOR(quer[j].second.first);
            }
        }
        return res;
    }
};