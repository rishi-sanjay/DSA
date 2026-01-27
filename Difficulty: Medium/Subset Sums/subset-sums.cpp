class Solution {
  public:
    void boss(vector<int> &arr,int sum,int idx,vector<int> &ans){
         ans.push_back(sum);
        for(int i=idx;i<arr.size();i++){
            
            boss(arr,sum+arr[i],i+1,ans);
        }
       
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        boss(arr,0,0,ans);
        return ans;
    }
};