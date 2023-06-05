#include<bits/stdc++.h>
using namespace std;
int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int low = min(arr1[0],arr2[0]), high = max(arr1[n-1],arr2[m-1]);
        while(low<=high){
            int mid = low+(high-low)/2;
            int cnt1 = upper_bound(arr1,arr1+n,mid)-arr1;
            int cnt2 = upper_bound(arr2,arr2+m,mid)-arr2;
            if(cnt1+cnt2 <= k-1)low = mid+1;
            else high = mid-1;
        }
        return low;
    }