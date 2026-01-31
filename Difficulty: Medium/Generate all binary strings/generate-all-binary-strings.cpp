class Solution {
  public:
    void boss(int n,vector<string> &ans,string temp,int x){
        if(x==n){
            ans.push_back(temp);
            return;
        }
      boss(n,ans,temp + '0',x+1);
      boss(n,ans,temp + '1',x+1);
    }
    vector<string> binstr(int n) {
        // code here
         vector<string> ans;
         boss(n,ans,"",0);
         return ans;
    }
};