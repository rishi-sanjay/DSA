class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        ans[0]=nums[0];
        int money=ans[0];
        for(int i=1;i<n;i++){
            ans[i]=nums[i];
            int j=2;
            while(i-j>=0){
              ans[i]=max(ans[i-j]+nums[i],ans[i]);
              j+=1;
            }
              money=max(money,ans[i]);
        }
        return money;
    }
};