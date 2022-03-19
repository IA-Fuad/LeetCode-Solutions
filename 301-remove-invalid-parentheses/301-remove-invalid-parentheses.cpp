class Solution {
    int maxValidLen = -1;
    
    int updateBalance(int balance, char c) {
        if (c == '(') balance++;
        else if (c == ')') balance--;
        return balance;
    }
    
    vector<unordered_set<string>> seen;
    
    void rec(vector<string>& ans, const string& s, int i, string& validParentheses, int balance) {
        if (balance < 0) return;
        if (seen[i].find(validParentheses) != seen[i].end()) return;
        seen[i].insert(validParentheses);
        if (i == s.size()) {
            if (balance != 0) return;
            if (maxValidLen == -1) {
                maxValidLen = validParentheses.size();
            }
            if (validParentheses.size() == maxValidLen) {
                ans.push_back(validParentheses);
            }
            return;
        }
        
        validParentheses.push_back(s[i]);
        rec(ans, s, i+1, validParentheses, updateBalance(balance, s[i]));
        validParentheses.pop_back();
        if (s[i] == '(' or s[i] == ')') {
            rec(ans, s, i+1, validParentheses, balance);
        }
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        seen.resize(s.size()+1);
        vector<string> ans;
        string validParentheses = "";
        rec(ans, s, 0, validParentheses, 0);
        
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