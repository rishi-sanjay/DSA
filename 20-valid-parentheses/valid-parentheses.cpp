class Solution {
public:
    bool isValid(string q) {
        stack<int> s;
        for (char p : q) {
            if ((p == ')' || p == '}' || p == ']') && s.empty()){
                return false;
        }
            if (p == '(' || p == '{' || p == '['){
                s.push(p);
        }
        else if (p == ')' && s.top() == '(') {
            s.pop();
        }
        else if (p == '}' && s.top() == '{') {
            s.pop();
        }
        else if (p == ']' && s.top() == '[') {
            s.pop();
        }
        else return false;
    }
   if(s.empty()) return true;
   return false;
    }
};
