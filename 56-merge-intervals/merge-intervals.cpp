class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        vector<vector<int>>ans;
        sort(inter.begin(),inter.end());
        int st=inter[0][0],end=inter[0][1];
        for(int i=1;i<inter.size();i++){
            if(inter[i][0]<=end){
                st=min(inter[i][0],st);
                end=max(inter[i][1],end);
            }
            else if(inter[i][0]>end){
                ans.push_back({st,end});
                st=inter[i][0];
                end=inter[i][1];
            }
        }
        ans.push_back({st,end});
        return ans;
    }
};