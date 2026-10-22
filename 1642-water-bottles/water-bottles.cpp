class Solution {
public:
    int numWaterBottles(int num, int E) {
        int ans=num;
        while(num>=E){
            int d=num/E;
            int re=num%E;
            ans+=d;
            num=d+re;
        }
        return ans;
    }
};