class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans=1;
        for(int val:nums){
            if(val==0) return 0;
            else if(val<0)
               ans=-ans;
        }
        return ans;
    }
};