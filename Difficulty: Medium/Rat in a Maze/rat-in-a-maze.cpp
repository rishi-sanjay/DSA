class Solution {
  public:
   void boss(vector<vector<int>>& rat,int i,int j,string temp,vector<string>&ans,int n){
        if(i==(n-1) && j==(n-1)){
            ans.push_back(temp);
            return;
        }
        if(rat[i][j]==1){
            rat[i][j]=0;
            if(i!=0 && rat[i-1][j]!=0)                    //top
              boss(rat,i-1,j,temp +'U',ans,n);
            if(i!=(n-1) && rat[i+1][j]!=0)                    //down
               boss(rat,i+1,j,temp+'D',ans,n);
            if(j!=0 && rat[i][j-1]!=0)              //left
              boss(rat,i,j-1,temp+'L',ans,n);
            if(j!=(n-1) && rat[i][j+1]!=0)              //right
              boss(rat,i,j+1,temp+'R',ans,n); 
            rat[i][j]=1;
        }
    }
    vector<string> ratInMaze(vector<vector<int>>&rat) {
        // code here
         int n=rat.size();
         vector<string>ans;
         boss(rat,0,0,"",ans,n);
         sort(ans.begin(),ans.end());
         return ans;
         
    }
};