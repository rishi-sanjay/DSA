class Solution {
public:
    bool judgeCircle(string moves) {
        int up=0;
        int ri=0;
        for(char x:moves){
            if(x=='U') up+=1;
            else if(x=='D') up-=1;
            else if(x=='R') ri+=1;
            else ri-=1;
        }
        return (up==0 && ri==0);
    }
};