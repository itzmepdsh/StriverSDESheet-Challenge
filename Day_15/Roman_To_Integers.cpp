#define pr pair<char,int>
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0,n = s.length();
       for(int c = s.length()-1;c>=0;c--){
           if(s[c] == 'I'){ 
               if(c<n-1 && (s[c+1] == 'V'||s[c+1] == 'X'))
               ans -= 1;
             else
                 ans += 1;
            }
           if(s[c] == 'X'){ 
               if((c < n-1) &&(s[c+1] == 'C'||s[c+1] == 'L'))
               ans -= 10;
             else
                 ans += 10;
            }
           if(s[c] == 'C'){                       
               if((c < n) &&( s[c+1] == 'D'||s[c+1] == 'M'))
               ans -= 100;
             else
                 ans += 100;
            }
           if(s[c] == 'V')
             ans += 5;
           if(s[c] == 'L')
             ans += 50;
           if(s[c] == 'D')
             ans += 500;
           if(s[c] == 'M')
             ans += 1000;
           
       }
      return ans;
    }
};