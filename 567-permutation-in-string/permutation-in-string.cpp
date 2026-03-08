class Solution {
public:
    bool boss(vector<int>& freq1, vector<int>& freq2) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0), freq2(26, 0);
        for (char xx : s1) {
            freq1[xx - 'a']+=1;
        }
        int j = -1;
        for (int i = 0; i < s2.size(); i++) {
            freq2[s2[i] - 'a']+=1;
            if (i >= (s1.size() - 1)) {
                if (j != -1)
                    freq2[s2[j]-'a']-=1;
                if (boss(freq1, freq2)==true)
                    return true;
                j+=1;
            }
        }
        return false;
    }
};