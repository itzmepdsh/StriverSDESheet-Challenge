#include<bits/stdc++.h>
using namespace std;
int noOfStudentsreq(vector<int> A, int N, int mid){
        int num = 1;
        int cursum = 0;
        int i=0;
        while(i<N){
            cursum += A[i];
            if(cursum <= mid){
                i++;
            }
            else{
                num++;
                cursum = A[i];
                i++;
            }
        }
        return num;
    }
int books(vector<int> &A, int M) {
    int N = A.size();
    if(N<M)return -1;
        int low = *max_element(A.begin(),A.end());
        int high = 0;
        for(int i=0;i<N;i++){
            high += A[i];
        }
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(noOfStudentsreq(A,N,mid) <= M){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
}
