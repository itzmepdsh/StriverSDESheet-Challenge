class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int n = txt.length(), m = pat.length();
            string concat = pat+"#"+txt;
            int len = n+m+1;
            
            vector<int> zarr(len,0);
            int l=0,r=0;
            for(int i=1;i<len;i++){
                if(i>r){
                    l = i;
                    r = i;
                    while(r<len && concat[r-l] == concat[r])
                        r++;
                    zarr[i] = r-l;
                    r--;
                }
                else{
                    int j = i-l;
                    if(zarr[j] < r-i+1){
                        zarr[i] = zarr[j];
                    }
                    else{
                        l = i;
                        while(r<len && concat[r-l] == concat[r])
                            r++;
                        zarr[i] = r-l;
                        r--;
                    }
                }
            }
            
            vector<int> res;
            for(int i=m+1;i<len;i++){
                if(zarr[i] == m)
                    res.push_back(i-m);
            }
            return res;
        }
     
};