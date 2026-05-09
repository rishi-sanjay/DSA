class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string wor="";
        int n=s.size();
        int i=0;
        reverse(s.begin(),s.end());
        for(int i=0;i<n;i++){
            while(i<n && (isupper(s[i]) || isdigit(s[i]) || islower(s[i]))){
                wor+=s[i];
                i++;
            }
            if(wor != ""){
            reverse(wor.begin(),wor.end());
            ans+=" "+wor;
            wor.clear();
            }
        }
        
        return ans.substr(1);
    }
};