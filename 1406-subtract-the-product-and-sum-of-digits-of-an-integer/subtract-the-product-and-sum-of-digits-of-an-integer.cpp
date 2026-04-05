class Solution {
public:
    int subtractProductAndSum(int n) {
        long long pr=1;
        long long sum=0;
        while(n>0){
            int last=n%10;
            pr=1LL*pr*last;
            sum=sum+last;
            n/=10;
        }
        return (int) pr-sum;
    }
};