class Solution {
public:
    string largestOddNumber(string num) {
        int ans=0;
        int sz=num.size()-1;
        while(sz>=0){
            int di=num[sz]-'0';
            if(di&1) break;
            sz--;
        }
        return num.substr(0,sz+1);
    }
};