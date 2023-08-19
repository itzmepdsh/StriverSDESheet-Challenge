class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = 1;
        int beg = 0;
        for(int i=0;i<n;i++){
            int left = i-1, right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]){
                if(right-left+1 > maxlen){
                    maxlen = right-left+1;
                    beg = left;
                }
                left--;
                right++;
            }
            left = i;
            right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]){
                if(right-left+1 > maxlen){
                    maxlen = right-left+1;
                    beg = left;
                }
                left--;
                right++;
            }
        }
        return s.substr(beg,maxlen);
    }
};