class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int r = 0, l = 0, rem, idx=0, mxlen = 0,count;
        set<int> s;
        while (r < fruits.size()) {
            count=0,r=idx;
            rem = -1;
            while (r < fruits.size() && s.size() <= 2) {
                s.insert(fruits[r]);
                if (s.size() == 2) {
                    if (rem == -1 || rem != fruits[r]) {
                        rem = fruits[r];
                        idx = r;
                    }
                }
                if(s.size()<=2) count+=1;
                r += 1;
            }
            s.clear();
            mxlen = max(mxlen,count);
        }
        return mxlen;
    }
};