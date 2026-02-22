class Solution {
public:
    int maxArea(vector<int>& height) {
        int st=0;
        int end=height.size()-1;
        int ans=0;
        while(st<end){
           int wid=end-st;
           int pr=wid*min(height[st],height[end]);
           ans=max(pr,ans);
           if(height[st]>height[end])
                    end--;
            else 
                st++;
        }
        return ans;
    }
};