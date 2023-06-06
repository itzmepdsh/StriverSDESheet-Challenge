vector<int> Solution::repeatedNumber(const vector<int> &nums) {
    vector<int> A(nums.begin(),nums.end());
    int n = A.size();
    int rep;
    for(int i=0;i<n;i++){
        int idx = abs(A[i]);
        A[idx-1] = -A[idx-1];
        if(A[idx-1]>0){
            rep = idx;
            break;
        }
    }
    int miss = rep;
    for(int i=0;i<n;i++){
        A[i] = abs(A[i]);
        miss = miss^A[i]^(i+1);
    }
    return {rep,miss};
}