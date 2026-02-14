class Solution {
public:
    bool isValid(string p) {
        stack<char> s;
        for (char x : p) {
            if (x == '(' || x == '{' || x == '[')
                s.push(x);

            else if (x == ')' && !s.empty() && s.top() == '(')
                s.pop();
            else if (x == ']' && !s.empty() && s.top() == '[')
                s.pop();
            else if (x == '}' && !s.empty() && s.top() == '{')
                s.pop();
            else
                return false;
        }
        if (!s.empty())
            return false;
        return true;
    }
};