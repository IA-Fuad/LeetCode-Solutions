class Solution {
    int maxValidLen = -1;
    
    int updateBalance(int balance, char c) {
        if (c == '(') balance++;
        else if (c == ')') balance--;
        return balance;
    }
    
    void rec(unordered_set<string>& ans, const string& s, int i, string validParentheses, int balance) {
        if (balance < 0) return;
        if (i == s.size()) {
            if (balance != 0) return;
            if (maxValidLen == -1) {
                maxValidLen = validParentheses.size();
            }
            if (validParentheses.size() == maxValidLen) {
                ans.insert(validParentheses);
            }
            return;
        }
        rec(ans, s, i+1, validParentheses+s[i], updateBalance(balance, s[i]));
        if (s[i] == '(' or s[i] == ')') {
            rec(ans, s, i+1, validParentheses, balance);
        }
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> uniqueValidParentheses;
        rec(uniqueValidParentheses, s, 0, "", 0);
        vector<string> ans;
        for (auto p : uniqueValidParentheses) ans.push_back(p);
        return ans;
    }
};

/*

()()))

()())()
^   ^

""
(())

*/