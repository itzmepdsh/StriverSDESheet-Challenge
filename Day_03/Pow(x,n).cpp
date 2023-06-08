class Solution {
public:
    double helper(double x, long long n){
        //base case
        if(n==0)return 1;
        if(n<0){
            n = -n;
            double A = myPow(1/x,n/2);
            if(n%2==0)return A*A;
            return (1/x)*A*A;
        }
        double A = myPow(x,n/2);
        if(n%2==0)return A*A;
        return x*A*A;
    }
    double myPow(double x, int n) {
        return helper(x,(long long)n);
    }
};