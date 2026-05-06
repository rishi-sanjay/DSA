class Solution {
public:
    
    int countPrimes(int n) {
        if(n==1 || n ==0) return 0;
        vector<int> pri(n+1,0);
        pri[0]=1;
        pri[1]=1;
        int cout=0;
        for(int i=2;i<n;i++){
            if(pri[i]!=1){
              int  k=i;
                cout++;
                while(k<n){
                    pri[k]=1;
                    k+=i;
                }
            }
        }
        return cout;
    }
};