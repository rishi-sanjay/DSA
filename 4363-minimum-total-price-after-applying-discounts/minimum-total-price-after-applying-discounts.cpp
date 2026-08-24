class Solution {
public:
    double minPrice(vector<int>& pri, vector<int>& dis) {
        sort(pri.begin(),pri.end());
        sort(dis.begin(),dis.end());
        int n=pri.size()-1,m=dis.size()-1;
        double ans=0;
        while(n>=0){
            if(m>=0){
                ans+= (double)pri[n]*(100-dis[m])/100;
            }else{
                ans+=pri[n];
            }
            n-=1;
            m-=1;
        }
        return ans;
    }
};