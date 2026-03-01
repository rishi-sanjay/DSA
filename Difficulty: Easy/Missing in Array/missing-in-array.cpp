class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
       int  n=arr.size()+1;
        long long asum=accumulate(arr.begin(),arr.end(),0LL);
        long long sum= 1LL *n*(1 + n )/2;
        return sum-asum;
    }
};