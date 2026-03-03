class Solution {
  public:
    bool boss(double mid,vector<int> & arr, int k){
         int p=0;
         for(int i=1;i<arr.size();i++){
             p+=ceil((arr[i]-arr[i-1])/mid )-1;
         }
         return p<=k;
    }
    double minMaxDist(vector<int> &stat, int K) {
        // Code here
        double st=0.0,end=0.0;
        for(int i=1;i<stat.size();i++){
            end=max(end,(double)(stat[i]-stat[i-1]));
        }
        while(end-st>1e-6){
            double mid= (st+ end)/2;
            if(boss(mid,stat,K)==true){
                end=mid;
            }else{
                st=mid;
            }
        }
        return st;
    }
};