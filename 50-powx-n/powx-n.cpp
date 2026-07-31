class Solution {
public:
    double power(double x, long long n, double ans){
        if(n==0) 
           return ans;
        if(n%2 !=1){
            return power(x*x,n/2,ans);
        }else {
            return power(x*x,n/2,ans*x);
        }
    }
    double myPow(double x, int n) {
        long long b=n;
        if(n>=0){
            return power(x,n,1.0);
        }else
           return power(1/x,-b,1.0);
    }
};