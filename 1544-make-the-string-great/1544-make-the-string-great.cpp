class Solution {
public:
    string makeGood(string s) {
        stack<char> chars;
        int offset = 'a' - 'A';
        
        for (char c : s) {
            if (!chars.empty() and (chars.top()+offset == c or chars.top()-offset == c)) {
                chars.pop();
            }
            else {
                chars.push(c);
            }
        }
        
        string ans;
        while (!chars.empty()) {
            ans.push_back(chars.top());
            chars.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};