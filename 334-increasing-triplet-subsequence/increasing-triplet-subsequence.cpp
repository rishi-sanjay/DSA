class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a=INT_MAX;
        int b=a;
        int c=b;
        for(int val:nums){
            if(val<a)
                a=val;
            else if(val>a && val< b)
                b=val;
            else if(val>a && val>b && val<=c){
               c=val;
               return true;
            }
        }
        return false;
    }
};