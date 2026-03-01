class Solution {
public:
    bool canJump(vector<int>& nums) {
        int gas=nums[0];
        for(int i=1;i<nums.size();i++){
            if(gas>0){
                gas-=1;
                gas=max(gas,nums[i]);
            }else {
                return false;
            }
        }
        return true;
    }
};