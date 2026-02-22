class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz=digits.size()-1;
        int carr=0;
        int s=1;
    for(int i=sz;i>=0;i--){
        int sum=digits[i]+s+carr;
        carr=sum/10;
        if(carr==0){
            digits[i]=sum;
            return digits;
        }else{
            digits[i]=sum%10;
        }
        s=0;
    }
    vector<int>ans;
    ans.push_back(1);
    ans.insert(ans.end(), digits.begin(), digits.end());
    return ans;
    }
};