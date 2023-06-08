class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int target, int row, int n){
        int s = 0,e = n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(matrix[row][mid]==target)return true;
            else if(matrix[row][mid] < target) s = mid+1;
            else e = mid-1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size();
        int s = 0,e = m-1,lb = -1;
        //if(matrix[0][0]==target)return true;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(matrix[mid][0] < target){
                s  = mid+1;
            }
            else{
                lb = mid;
                e = mid-1;
            }
        }
        if(lb == -1)return binarySearch(matrix,target,m-1,n);
        if(matrix[lb][0] == target)return binarySearch(matrix,target,lb,n);
        if(lb != 0)return binarySearch(matrix,target,lb-1,n);
        return false;
    }
};