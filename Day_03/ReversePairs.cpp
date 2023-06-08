class Solution {
public:
    int brr[50000] = {0};
    int Merge(vector<int>& arr, int low, int mid, int high){
        int i=low,j=mid+1,k=low;
        int cnt = 0;
        int a = mid+1;
        for(int b=low;b<=mid;b++){
            while(a<=high && arr[b] > 2*(long long)arr[a]){
                a++;
            }
            cnt += a-(mid+1);
        }
        while(i<=mid && j<=high){
            if(arr[i] <= arr[j]){
                brr[k++] = arr[i++];
            }
            else{
                brr[k++] = arr[j++];
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
    
    int MergeSort(vector<int>& arr,int low, int high){
        int cnt = 0;
        if(low==high)return cnt;
        int mid = low + (high-low)/2;
        cnt += MergeSort(arr,low,mid);
        cnt += MergeSort(arr,mid+1,high);
        cnt += Merge(arr,low,mid,high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return MergeSort(nums,0,n-1);
    }
};