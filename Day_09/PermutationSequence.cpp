class Solution {
public:
    string res = "";
    void generate_permutation(string s, int n, int k, int i, int& cnt){
        //base case
        if(i==n){
            if(cnt==k){
                res = s;
            }
            cnt++;
            return;
        }
        if(cnt > k)return;
        //recursive case
        for(int j=i;j<n;j++){
            swap(s[i],s[j]);
            generate_permutation(s,n,k,i+1,cnt);
            // swap(s[i],s[j]);
        }
    }
    string getPermutation(int n, int k) {
        string s = "";
        for(char i='1';i<='0'+n;i++){
            s += i;
        }
        int cnt = 1;
        generate_permutation(s,n,k,0,cnt);
        return res;
    }
};