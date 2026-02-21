class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size()-1;
        int m=b.size()-1;
        int carry=0;
        string ans="";
        while(n >=0 || m >=0){
            int x=0,y=0;
            if(n>=0) x=a[n]-'0';
            if(m>=0) y=b[m]-'0';
            int sum= x+y+ carry;
            ans=to_string(sum%2)+ans;
            carry=sum/2;
            n-=1;
            m-=1;
        }
        if(carry !=0) ans=to_string(1)+ans;
        return ans;
    }
};