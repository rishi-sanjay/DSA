class Solution {
public:
    int call(int m, int n,vector<vector<int>>&dp){
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=0) return dp[m][n];
        //left
        int left=0,up=0;
        if(n>0)
        left=call(m,n-1,dp);
        if(m>0)
        up=call(m-1,n,dp);
        return dp[m][n]=left+up;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        return call(m-1,n-1,dp);
    }
};