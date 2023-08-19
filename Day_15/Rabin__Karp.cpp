typedef long long int ll;
class Solution
{
    int mod = 1e9+7;
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            int n = txt.length(), m = pat.length();
            vector<ll> pow(n+1);
            pow[0] = 1;
            for(int i=1;i<=n;i++){
                pow[i] = (31*pow[i-1])%mod;
            }
            vector<ll> pre(n+1,0);
            for(int i=0;i<n;i++){
                pre[i+1] = (pre[i] + pow[i]*(txt[i]-'a'+1))%mod;
            }
            
            ll hash = 0;
            for(int i=0;i<m;i++){
                hash = (hash + pow[i]*(pat[i]-'a'+1))%mod;
            }
            
            vector<int> res;
            for(int i=0;i<=n-m;i++){
                if((hash*pow[i])%mod == (pre[i+m]+mod-pre[i])%mod)
                    res.push_back(i+1);
            }
            if(res.size()==0)return {-1};
            return res;
        }
     
};