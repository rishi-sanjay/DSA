class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int> m;
        for(int val:nums){
            int sec=val+k;
            int tir=val-k;
            if(m.find(sec)!=m.end())
                count+=m[sec];
            if(m.find(tir)!=m.end())
                count+=m[tir];
            m[val]++;
        }
        return count;
    }
};