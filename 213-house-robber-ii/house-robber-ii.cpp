class Solution {
public:
   int call(vector<int>&nums,int st,int sz){
    int prev2=0;
    if(st>sz) return 0;
    int prev=nums[st];
    for(int i=st+1;i<sz;i++){
        int curr=max(prev2+nums[i],prev);
        prev2=prev;
        prev=curr;
    }
    return prev;
   }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
       return max(call(nums,0,n-1),call(nums,1,n));
    }
};