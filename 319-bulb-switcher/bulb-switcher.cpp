class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0) return 0;
        int i=1;
        int ans;
        while(i*i <=n){
            ans=i;
            i+=1;
            
        }
        return ans;
    }
};