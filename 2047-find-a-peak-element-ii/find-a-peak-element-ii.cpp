class Solution {
public:
int maxrow(vector<vector<int>>&mat,int col){
    int ma=INT_MIN;
    int row=mat.size();
    int ans=-1;
    for(int i=0;i<row;i++){
        if(mat[i][col]>ma){
            ans=i;
            ma=mat[i][col];
        }
    }
    return ans;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int pt=0;
        vector<int> ans;
        int st=0;
        int col=mat[0].size()-1;
        int mid;
        while(st<=col){
            mid=st+(col-st)/2;
            int i=maxrow(mat,mid);
            int left=mid-1>=0?mat[i][mid-1]:-1;
            int right=mid+1<=col?mat[i][mid+1]:-1;
            if(mat[i][mid]>left&&mat[i][mid]>right){
                ans.push_back(i);
                ans.push_back(mid);
                return ans;
            }else if(mat[i][mid]<left){
                col=mid-1;
            }else{
                st=mid+1;
            }
        }
        
        return ans;
    }
};