class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans=0;
        for(int val:nums){
            if(m.find(val)==m.end())
                m[val]++;
            else{
                ans+=m[val]++;
            }
        }
        return ans;
    }
};