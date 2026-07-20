class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long ans=0,sum=INT_MIN ;
        int sub=0;
        for(int i=0;i<nums.size();i++){
            ans =ans + nums[i];
            if(i>=(k-1)){
                sum=max(ans,sum);
                ans-=nums[sub];
                sub+=1;
            }
        }
        return (double) sum/k;
    }
};