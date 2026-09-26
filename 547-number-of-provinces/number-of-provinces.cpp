class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      int ans=0;
      int n=isConnected.size();
       vector<int>vis(n,0);
       for(int i=0;i<n;i++){
         if(vis[i] !=1){
            ans+=1;
            vis[i]=1;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int j=0;j<n;j++){
                    if(vis[j]==0 && isConnected[node][j]==1){
                         vis[j]=1;
                         q.push(j);
                }
            }
            }
        }
        }
      
    return ans;
    }
};