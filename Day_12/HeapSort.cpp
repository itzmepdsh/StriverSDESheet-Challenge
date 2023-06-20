// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int maxidx = i;
        int leftchild = 2*i+1;
        if(leftchild < n && arr[leftchild] > arr[maxidx]){
            maxidx = leftchild;
        }
        int rightchild = 2*i+2;
        if(rightchild < n && arr[rightchild] > arr[maxidx]){
            maxidx = rightchild;
        }
        if(maxidx != i){
            swap(arr[maxidx],arr[i]);
            heapify(arr,n,maxidx);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    {
        for(int i=n-1;i>=0;i--){
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        int heapsize = n;
        while(heapsize > 1){
            swap(arr[0],arr[heapsize-1]);
            heapsize--;
            heapify(arr,heapsize,0);
        }
    }
};