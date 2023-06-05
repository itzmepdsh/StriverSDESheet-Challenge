#include<bits/stdc++.h>
using namespace std;
int binarysearch(vector<int>& nums, int target, int s, int e){
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid] < target)s = mid+1;
            else e = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        //if(nums[0] < nums[n-1])return binarysearch(nums,target,0,n-1);
        int pivot = 0,s=0,e=n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] < nums[0]){
                pivot = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        cout<<pivot<<endl;
        int res = binarysearch(nums,target,0,pivot-1);
        if(res == -1)res = binarysearch(nums,target,pivot,n-1);
        return res;
    }