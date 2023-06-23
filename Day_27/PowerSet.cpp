class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
            vector<string> res;
            int n = s.length();
            for(int k=1;k<(1<<n);k++){
                string str = "";
                for(int i=0;i<n;i++){
                    if((1<<i)&k){
                        str += s[i];
                    }
                }
                res.push_back(str);
            }
            sort(res.begin(),res.end());
            return res;
		}
};