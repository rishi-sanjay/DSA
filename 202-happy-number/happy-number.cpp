class Solution {
public:
    int getnumber(int p){
        int ans=0;
        while(p>0){
            int last=p%10;
            ans+=(last * last);
            p/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int sl=n;
        int fa=getnumber(n);
        while(fa !=1 && fa!= sl){
            sl=getnumber(sl);
            fa=getnumber(getnumber(fa));
        }
        return fa==1;
    }
};