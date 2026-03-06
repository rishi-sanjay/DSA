class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN, sum=0;
        int j=-1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(i>=(k-1)){
                if(j !=-1) sum -=nums[j];
                j++;
                ans=max(ans,sum/k);
            }
        }
        return ans;
    }
};