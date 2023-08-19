class Solution {
public:
    vector<int> build_pi_table(string pat){
        int m = pat.length();
        vector<int> lps(m,0);
        for(int i=1;i<m;i++){
            int j = lps[i-1];
            while(j>0 && pat[j] != pat[i]){
                j = lps[j-1];
            }
            if(pat[i] == pat[j])
                j++;
            lps[i] = j;
        }
        return lps;
    }
    
    int strStr(string txt, string pat) {
        int n = txt.length(), m = pat.length();
        vector<int> lps = build_pi_table(pat);
        int i=0,j=0;
        while(i<n){
            if(txt[i] == pat[j]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
            if(j==m)
                return i-m;
        }
        return -1;
    }
};