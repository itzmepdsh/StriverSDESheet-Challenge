class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=0,j=0;
    	int cnt = 0, res = 0;
    	while(i<n){
    	    while(j<n && dep[j] < arr[i]){
    	        cnt--;
    	        j++;
    	    }
    	    if(arr[i] <= dep[i]){
    	        cnt++;
    	        res = max(res,cnt);
    	        i++;
    	    }
    	}
    	return res;
    }
};