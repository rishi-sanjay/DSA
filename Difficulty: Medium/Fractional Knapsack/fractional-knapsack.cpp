class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<int,int>>res;
        for(int i=0;i<wt.size();i++){
            res.push_back({val[i],wt[i]});
        }
        sort(res.begin(),res.end(),[](auto &a, auto b){
            return (double)a.first/a.second > (double)b.first/b.second;
        });
        double ans=0.0;
        int i=0;
        while(i<res.size() && capacity>=res[i].second){
            ans+=res[i].first;
            capacity-=res[i].second;
            i++;
        }
        while(i< res.size() && capacity>0){
            ans+= capacity * (double) res[i].first/res[i].second; 
            capacity=0;
        }
        return ans;
    }
};
