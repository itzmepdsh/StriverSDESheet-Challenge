class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        vector<int> cumsum(n,0);
        cumsum[0] = A[0];
        int maxlen = 0;
        if(A[0]==0)maxlen = 1;
        for(int i=1;i<n;i++){
            cumsum[i] = cumsum[i-1]+A[i];
            if(cumsum[i] == 0)maxlen = max(maxlen,i+1);
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(cumsum[i]) != mp.end()){
                maxlen = max(maxlen,i-mp[cumsum[i]]);
            }
            else{
                mp[cumsum[i]] = i;
            }
        }
        return maxlen;
    }
};