class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int tsum=accumulate(nums.begin(),nums.end(),0);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(tsum==sum)
               return i;
            tsum-=nums[i];
        }
        return -1;
    }
};