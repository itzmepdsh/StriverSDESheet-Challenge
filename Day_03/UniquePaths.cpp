class Solution {
public:
    int uniquePaths(int m, int n) {
        
        //using maths
        //In m*n matrix, we have to take (m-1) down and (n-1) right steps 
        // total no. of steps = (m-1) + (n-1) i.e, D D D R D R...D
        //So total no of permutation of given word = (total steps)!/(m-1)!(n-1)!
        if(m==1 || n==1)return 1;
        if(m<n)swap(m,n);
        m = m-1;n = n-1;
        long long int i = 1,j=m+1,res = 1;
        while(j<=m+n){
            res *= j;
            res /= i;
            i++;j++;
        }
        return (int)res;

        //using somewhat similar to dp

        // vector<vector<int>> vec(m,vector<int>(n,1));
        // for(int i=1;i<m;i++){
        //     for(int j=1;j<n;j++){
        //         vec[i][j] = vec[i-1][j] + vec[i][j-1];
        //     }
        // }
        // return vec[m-1][n-1];
    }
};