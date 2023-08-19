class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> dp(n,1), sum(n,0);
	    sum[0] = arr[0];
	    for(int i=1;i<n;i++){
	        sum[i] = arr[i];
	        for(int prev = 0;prev<i;prev++){
	            if(arr[prev] < arr[i]){
	                sum[i] = max(sum[i],arr[i] + sum[prev]);
	            }
	        }
	    }
	    int res = 0;
	    for(int i=0;i<n;i++){
	            res = max(res,sum[i]);
	    }
	    return res;
	}  
};