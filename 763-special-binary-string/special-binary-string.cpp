class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int count = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                count++;
            else
                count--;

            // Found one special substring
            if (count == 0) {
                // remove outer 1 and 0
                string inner = s.substr(start + 1, i - start - 1);
                // recursively solve inside
                parts.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        // Sort descending for lexicographically largest
        sort(parts.begin(), parts.end(), greater<string>());

        string res;
        for (auto& x : parts)
            res += x;
        return res;
    }
};
