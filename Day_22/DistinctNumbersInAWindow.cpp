vector<int> Solution::dNums(vector<int> &arr, int b) {
    int i=0,j=0;
    int n = arr.size();
    vector<int> res;
    unordered_map<int,int> mp;
    while(j<n){
        mp[arr[j]]++;
        if(j-i+1 < b){
            j++;
        }
        else if(j-i+1 == b){
            res.push_back(mp.size());
            mp[arr[i]]--;
            if(mp[arr[i]] == 0)mp.erase(arr[i]);
            i++;
            j++;
        }
    }
    return res;
}
