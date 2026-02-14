class Solution {
public:
    bool isvalid(char x) {
         if(isalpha(x)) return true;
         if(isdigit(x)) return true;
   return false;
    }
    bool isPalindrome(string s) {
        int st = 0;
        int end = s.size() - 1;
        while (st < end) {
            while (isvalid(s[st]) == false && st<end)
                st++;
            while (isvalid(s[end]) == false && st<end) 
                end--;

            if (tolower(s[st]) != tolower(s[end]))
                return false;
            st++;
            end--;
        }
        return true;
    }
};