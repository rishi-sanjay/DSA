class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sl=nums[0];
        int fa=nums[0];
        do{
            sl=nums[sl];
            fa=nums[nums[fa]];
        }while(sl != fa);
        sl=nums[0];
        while(sl != fa){
            sl=nums[sl];
            fa=nums[fa];
        }
        return sl;
    }
};