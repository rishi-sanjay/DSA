class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& nums) {
        int sz=nums.size();
        if(sz==2) return true;
        int x=nums[0][0];
        int y=nums[1][0];
        int p=nums[0][1];
        int q=nums[1][1];
        for(int i=2;i<sz;i++){
            int a=nums[i][0];
            int b=nums[i][1];
            if(((q-p)*(a-y)) != ((y-x)*(b-q)))
               return false;
        }
        return true;
    }
};