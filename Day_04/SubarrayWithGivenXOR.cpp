int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int,int> mp;
    int XR = 0;
    mp[XR]++;
    int cnt = 0;
    for(int i=0;i<n;i++){
        XR ^= A[i];
        if(mp.find(XR^B) != mp.end()){
            cnt += mp[XR^B];
        }
        mp[XR]++;
    }
    return cnt;
}