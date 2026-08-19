class Solution {
public:
    int candy(vector<int>& ratings) {
        int sz = ratings.size();
        vector<int> st(sz, 1);
        int ans = 0, next;
        for (int i = 1; i < sz; i++) {
            if (ratings[i - 1] < ratings[i])
                st[i]=st[i-1]+1;
        }
        int curr = st[sz - 1];
        ans = curr;
        next=curr;
        for (int i = sz - 2; i >= 0; i--) {
        
            if (ratings[i] > ratings[i+1]) {
                st[i]=max(st[i+1]+1,st[i]);
            }

            ans += st[i];
        }

        return ans;
    }
};