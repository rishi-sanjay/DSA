class Solution {
public:  int call(int m, int n,vector<vector<int>>&dp,vector<vector<int>>& obs){
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=0) return dp[m][n];
        //left
        int left=0,up=0;
        if(n>0 && obs[m][n-1]!=1 )
        left=call(m,n-1,dp,obs);
        if(m>0 &&obs[m-1][n]!=1 )
        up=call(m-1,n,dp,obs);
        return dp[m][n]=left+up;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m=obs.size();
        int n=obs[0].size();
         vector<vector<int>>dp(m,vector<int>(n,0));
         if(obs[m-1][n-1]==1) return 0;
        return call(m-1,n-1,dp,obs);
    }
};