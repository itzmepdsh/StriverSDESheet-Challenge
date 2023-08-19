class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.length();
        long long int res = 0;
        while(i<n && s[i] == ' '){
            i++;
        }
        bool ispos = true;
        if(s[i] == '-' || s[i] == '+'){
            if(s[i] == '-')ispos = false;
            i++;
        }
        while(i<n && s[i]>='0' && s[i] <= '9'){
            int dig = s[i]-'0';
            if(ispos){
                res = (res*10+dig < INT_MAX)? (res*10+dig) :INT_MAX;
            }
            else{
                dig = -dig;
                res = (res*10+dig > INT_MIN)? (res*10+dig) :INT_MIN;
            }
            if(res == INT_MAX || res == INT_MIN)return res;
            i++;
        }
        return res;
    }
};