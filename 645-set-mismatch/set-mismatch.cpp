class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long sz = nums.size();
         vector<int> ans(2, 0);
        long long as = 0;
        long long ass = 0;
        long long nss = 0;
        long long ns = (sz * (sz + 1)) / 2;
        long i = 1;
        for (int val : nums) {
            as += val;
            ass += (val * val);
            nss += (i * i);
            i++;
        }
    long long n=as-ns;
    long long p=(ass-nss)/n;
    ans[0]= (int)(n+p)/2;
    ans[1]=(int) -n+ans[0];
    return ans;
    }
};