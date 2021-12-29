class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (char b : s) {
            if (b == '(' || b == '{' || b == '[') brackets.push(b);
            else {
                char left = '(';
                if (b == '}') left = '{';
                else if (b == ']') left = '[';
                if (brackets.empty() || brackets.top() != left) return false;
                brackets.pop();
            }
        }
        return brackets.empty();
    }
};