class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>mnn(n,INT_MAX);
        mnn[n-1]=nums[n-1];
        for(int i=nums.size()-2;i>=0;i--){
           mnn[i]=min(mnn[i+1],nums[i]);
        }
        int mxx=nums[0];
        for(int i=0;i<n;i++){
            if(mxx<nums[i]) mxx=nums[i];
            if(mxx-mnn[i]<=k) return i;
        }
        return -1;
    }
};