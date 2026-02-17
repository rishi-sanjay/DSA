class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i=1;
        while(num>i*i)
           i+=1;
        if(i*i==num) return true;
        return false;
    }
};