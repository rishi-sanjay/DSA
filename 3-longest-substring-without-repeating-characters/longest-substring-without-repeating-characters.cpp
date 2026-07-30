class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,maxlen=0;
        unordered_map<char,int> m;
        for(int r=0;r<s.length();r++){
            if(m.find(s[r]) != m.end() && (l<=m[s[r]])){
                l=m[s[r]]+1;
            }
            m[s[r]]=r;
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};