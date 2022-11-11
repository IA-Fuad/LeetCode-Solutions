class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        stack<char> str;
        
        for (char c : s) {
            if (!str.empty() and str.top() == c) {
                str.pop();
            }
            else {
                str.push(c);
            }
        }
        
        while (!str.empty()) {
            ans.push_back(str.top());
            str.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};