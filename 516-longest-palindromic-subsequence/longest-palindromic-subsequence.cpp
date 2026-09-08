class Solution {
public:
int call(string &s,string&t,int i,int j, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) 
       return dp[i][j]=1+ call(s,t,i-1,j-1,dp);
    return dp[i][j]=0 + max(call(s,t,i-1,j,dp),call(s,t,i,j-1,dp));
}
    int longestCommonSubsequence(string &text1, string &text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return call(text1,text2,m-1,n-1,dp);
    }

    int longestPalindromeSubseq(string s) {
        string z=s;
         reverse(z.begin(),z.end());
        return longestCommonSubsequence(s,z);
    }
};