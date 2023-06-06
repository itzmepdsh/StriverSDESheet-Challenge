long long brr[500000] = {0};
    long long int Merge(long long arr[], long long low, long long mid, long long high){
        long long int i=low,j=mid+1,k=low;
        long long int cnt = 0;
        while(i<=mid && j<=high){
            if(arr[i] <= arr[j]){
                brr[k++] = arr[i++];
            }
            else{
                brr[k++] = arr[j++];
                cnt += (mid-i+1);
            }
        }
        while(i<=mid){
            brr[k++] = arr[i++];
        }
        while(j<=high){
            brr[k++] = arr[j++];
        }
        for(int a=low;a<=high;a++){
            arr[a] = brr[a];
        }
        return cnt;
    }
    
    long long int MergeSort(long long arr[], long long low, long long high){
        long long int cnt = 0;
        if(low==high)return cnt;
        long long int mid = low + (high-low)/2;
        cnt += MergeSort(arr,low,mid);
        cnt += MergeSort(arr,mid+1,high);
        cnt += Merge(arr,low,mid,high);
        return cnt;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return MergeSort(arr,0,N-1);
    }