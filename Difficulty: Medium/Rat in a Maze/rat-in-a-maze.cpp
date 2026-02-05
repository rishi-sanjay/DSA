class Solution {
  public:
    void boss(vector<string> &ans,vector<vector<int>> & m,int i,int j,string s,int n){
       if(i==n && j==n){
           ans.push_back(s);
           return;
       }
       if(m[i][j]==1){
           m[i][j]=0;
       
     if(i !=0 &&m[i-1][j]==1){//top
         boss(ans,m,i-1,j,s+'U',n);
     }if(i !=(n) && m[i+1][j]==1){
         boss(ans,m,i+1,j,s+'D',n);
     }if(j !=0 && m[i][j-1]==1){
         boss(ans,m,i,j-1,s+'L',n);
     }        
     if(j !=(n) && m[i][j+1]==1){
         boss(ans,m,i,j+1,s+'R',n);
     }
     m[i][j]=1;
    }
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector <string> ans;
        int n=maze.size()-1;
        boss(ans,maze,0,0,"",n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};