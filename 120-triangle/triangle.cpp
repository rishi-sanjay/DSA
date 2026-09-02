class Solution {
public:
     int call(vector<vector<int>>&tri,int m,int n,vector<vector<int>>&dp){
        int sz=tri.size();
        if(m==sz-1) return tri[m][n];
        if(dp[m][n]!=INT_MAX) return dp[m][n];
        //down
        int dow=INT_MAX,left=INT_MAX;
        dow=call(tri,m+1,n,dp);
        left=call(tri,m+1,n+1,dp);
        return dp[m][n]=tri[m][n]+min(dow,left);
     }
    int minimumTotal(vector<vector<int>>& tri) {
        int m=tri.size();
        vector<vector<int>>dp(m,vector<int>(m,INT_MAX));
        return call(tri,0,0,dp);
    }
};