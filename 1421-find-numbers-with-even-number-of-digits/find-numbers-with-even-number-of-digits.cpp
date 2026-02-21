class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int val:nums){
            int dig=log10(val)+1;
            if (dig%2==0) ans+=1;
        }
        return ans;
    }
};