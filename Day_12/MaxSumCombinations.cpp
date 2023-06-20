vector<int> Solution::solve(vector<int> &arr, vector<int> &brr, int k) {
    int n = arr.size();
    sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        priority_queue<int> pq;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(pq.size() < k)pq.push(-(arr[i]+brr[j]));
                else{
                    if((arr[i]+brr[j]) > -pq.top()){
                        pq.pop();
                        pq.push(-(arr[i]+brr[j]));
                    }
                    else
                        break;
                }
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(-pq.top());
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
}