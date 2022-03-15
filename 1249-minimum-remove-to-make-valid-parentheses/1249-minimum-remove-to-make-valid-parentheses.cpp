class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> left;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left.push(i);
            }
            else if (s[i] == ')') {
                if (left.empty()) {
                    s[i] = '*';
                }
                else {
                    left.pop();
                }
            }
        }
        while (!left.empty()) {
            s[left.top()] = '*';
            left.pop();
        }
        string validString;
        for (char c : s) {
            if (c != '*') {
                validString.push_back(c);
            }
        }
        return validString;
    }
};