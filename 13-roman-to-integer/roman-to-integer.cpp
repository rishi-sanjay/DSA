class Solution {
public:
 int se(char p){
    if(p=='I') return 1;
    else if(p=='V') return 5;
    else if(p=='X') return 10;else if(p=='L') return 50;
    else if(p=='C') return 100; else if(p=='D') return 500;
    else 
       return 1000;
 }
    int romanToInt(string s) {
        int ans=se(s[s.size()-1]);
        for(int i=s.size()-2;i>=0;i--){
             int ne=se(s[i+1]);
             int cu=se(s[i]);
             if(ne>cu)
                ans-=cu;
            else 
              ans+=cu;
        }
        return ans;
    }
};