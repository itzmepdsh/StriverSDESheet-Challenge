#include<bits/stdc++.h>
using namespace std;
int NthRoot(int n, int m)
	{
	    // Code here.
	    int root;
	    int low = 0,high = m;
	    while(low<=high){
	        int mid = low + (high-low)/2;
	        if(pow(mid,n) <= m){
	            root = mid;
	            low = mid+1;
	        }
	        else{
	            high = mid-1;
	        }
	    }
	    if(pow(root,n) != m)return -1;
	    return root;
	}  