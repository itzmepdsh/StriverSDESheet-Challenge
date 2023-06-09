void findsum(vector<int> arr, int n, vector<int>& res, int i, int sum){
        //base case
        if(i==n){
            res.push_back(sum);
            return;
        }
        //recursive case
        findsum(arr,n,res,i+1,sum);
        findsum(arr,n,res,i+1,sum+arr[i]);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> res;
        int sum = 0;
        findsum(arr,N,res,0,sum);
        return res;
    }