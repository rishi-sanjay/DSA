class Solution {
public:
    int reverseBits(int n) {
        if(n==0) return 0;
        int ans=0;
        int i=-1;
        while(n>0){
            ans= (ans<<1) | (n&1);
            n/=2;
            i+=1;
        }
        ans=ans<<(31-i);
        return ans;
    }
};