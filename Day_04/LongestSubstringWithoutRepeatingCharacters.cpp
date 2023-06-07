class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<pair<int,int>> hash(128,{0,-1});
        int len = 0, cur_len = 0;
        int i=0,j=0;
        while(j<s.length()){
            if(hash[int(s[j])].first == 0){
                hash[int(s[j])].first++;
                hash[int(s[j])].second = j;
                cur_len++;
                j++;
            }
            else{
                len = max(len,cur_len);
                int temp = i;
                i = hash[int(s[j])].second+1;
                for(int k=temp;k<i;k++){
                    hash[int(s[k])].first = 0;
                }
                cur_len = j-i;
                // hash[int(s[j])].first++;
                // hash[int(s[j])].second = j;
                // j++;
            }
        }
        len = max(len,cur_len);
        return len;
        // int n = s.length();
        // int i=0,j=0;
        // int maxlen = 0,curlen = 0;
        // map<char,int> mp;
        // while(j<n){
        //     if(mp.find(s[j]) == mp.end()){
        //         mp[s[j]] = j;
        //         curlen++;
        //         j++;
        //     }
        //     else{
        //         maxlen = max(maxlen,curlen); 
        //         i = mp[s[j]]+1;
        //         for(pair<char,int> pr : mp){
        //             if(pr.second < i){
        //                 mp.erase(pr.first);
        //             }
        //         }
        //         curlen = j-i; 
        //     }
        // }
        // maxlen = max(maxlen,curlen);
        // return maxlen;
    }
};