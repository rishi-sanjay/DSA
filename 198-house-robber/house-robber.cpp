class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        ans[0]=nums[0];
        for(int i=1;i<n;i++){
            if(i-2>=0)
               ans[i]=max(ans[i-2]+nums[i],ans[i-1]);
            else
               ans[i]=max(ans[i-1],nums[i]);
        }
        return ans[n-1];
    }
};