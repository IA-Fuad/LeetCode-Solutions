class Solution {
public:
    int scoreOfParentheses(string s) {
        int scores = 0, balance = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') balance++;
            else {
                balance--;
                if (s[i-1] == '(') {
                    scores += (1 << balance);
                }
            }
        }
        return scores;
    }
};

/*

(((()))())()()()

8+4+2+

*/