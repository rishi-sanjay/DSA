class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0,ans=0,r=0,l=0;
        int sz=nums.size()-1;
        unordered_map<int,int>m;
        while(r<nums.size()){
            xr^=nums[r];
            if(xr != 0 ){
                ans=max(ans,r+1);
            }
            if(xr ==0 && m.size() >1)
               ans=max(ans,r);
            if(m.find(xr)==m.end())
               m[xr]++;
            r+=1;
        }
        return ans;
    }
};