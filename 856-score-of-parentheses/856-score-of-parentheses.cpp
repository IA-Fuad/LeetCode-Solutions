class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> scores;
        scores.push(0);
        for (char c : s) {
            if (c == '(') scores.push(0);
            else {
                int prev = scores.top();
                scores.pop();
                int prevPrev = scores.top();
                scores.pop();
                scores.push(max(1, 2 * prev) + prevPrev);
            }
        }
        return scores.top();
    }
};

/*

(((()))())()()()

[1]

*/