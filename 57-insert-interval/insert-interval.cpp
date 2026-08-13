class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& ne) {
        vector<vector<int>> ans;
        int i=0;
        int sz=inter.size();
        while(i<sz && inter[i][1]<ne[0]){
            ans.push_back({inter[i][0],inter[i][1]});
            i+=1; 
        }
        while(i<sz &&  inter[i][0]<=ne[1]){
            ne[0]=min(ne[0],inter[i][0]);
            ne[1]=max(ne[1],inter[i][1]);
            i+=1;
        }
        ans.push_back({ne[0],ne[1]});
        while(i<sz){
              ans.push_back({inter[i][0],inter[i][1]});
            i+=1;
        }
        return ans;
    }
};