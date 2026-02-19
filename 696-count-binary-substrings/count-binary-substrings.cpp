class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        int pr=0;
        int curr=1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]) curr+=1;
            else{
                ans+=min(pr,curr);
                pr=curr;
                curr=1;
            }
        }
        ans+=min(pr,curr);
        return ans;
    }
};