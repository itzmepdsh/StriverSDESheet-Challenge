#include<bits/stdc++.h>
using namespace std;
int numOfelements(vector<vector<int>> &matrix, int R, int C, int key){
        int cnt = 0;
        for(int i=0;i<R;i++){
            int ub = C,low=0,high=C-1;
            while(low<=high){
                int mid = low+(high-low)/2;
                if(matrix[i][mid] > key){
                    ub = mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            cnt += ub;
        }
        return cnt;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int low = 1,high = 1000000000;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(numOfelements(matrix,R,C,mid) > (R*C)/2){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
int findMedian(vector<vector<int> > &A) {
    int r = A.size(),c = A[0].size();
    return median(A,r,c);
}
