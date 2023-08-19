class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        int i=2;
        while(i<=n){
            string ans = "";
            int cnt = 1;
            char say = res[0];
            for(int i=1;i<res.length();i++){
                if(res[i] == say)cnt++;
                else{
                    ans += to_string(cnt);
                    ans += say;
                    cnt = 1;
                    say = res[i];
                }
            }
            ans += to_string(cnt);
            ans += say;
            res = ans;
            i++;
        }
        return res;
    }
};