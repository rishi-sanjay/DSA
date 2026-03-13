class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, count = 0;
        for (char x : s) {
            if (!isalpha(x)) {
                count=0;
            }else{
                count+=1;
                ans = count;
            }
        }
        return ans;
    }
};