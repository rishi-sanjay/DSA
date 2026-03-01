class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>> res;
        for(int i=0;i<end.size();i++){
            res.push_back({start[i],end[i]});
        }
        sort(res.begin(),res.end(),[](auto &a, auto &b){
            return a.second < b. second;
        });
        int ans=1;
        int la=res[0].second;
        for(int i=1;i<end.size();i++){
            if(la<res[i].first){
                la=res[i].second;
                ans++;
            }
        }
        return ans;
    }
};