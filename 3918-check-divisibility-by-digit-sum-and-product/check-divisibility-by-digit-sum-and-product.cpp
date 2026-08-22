class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,pr=1;
        int k=n;
        while(k>0){
            int last=k%10;
            sum+=last;
            pr*=last;
            k/=10;
        }
       return (n%(sum+pr)==0);
    }
};