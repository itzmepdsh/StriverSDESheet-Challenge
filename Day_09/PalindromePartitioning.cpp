class Solution {
public:
    bool isPalindrome(string s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }

    void palindrome_partitioned(string s, int n,vector<vector<string>>& res, vector<string> out, int idx){
        //base case
        if(idx == n){
            res.push_back(out);
            return;
        }
        //recursive case
        for(int len=1;len <= n-idx;len++){
            string curstr = s.substr(idx,len);
            if(isPalindrome(curstr)){
                out.push_back(curstr);
                palindrome_partitioned(s,n,res,out,idx+len);
                out.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> res;
        vector<string> out;
        palindrome_partitioned(s,n,res,out,0);
        return res;
    }
};