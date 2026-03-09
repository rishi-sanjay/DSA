class Solution {
public:
    int countOdds(int low, int high) {
        if(high & 1) high+=1;
        if(low & 1) low-=1;
        return (high-low)/2;
    }
};