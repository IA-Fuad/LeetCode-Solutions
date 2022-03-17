class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> scores;
        for (char c : s) {
            if (c == '(') scores.push(0);
            else {
                if (scores.top() == 0) {
                    scores.pop();
                    scores.push(1);
                }
                else {
                    int currentScore = 0;
                    while (scores.top() != 0) {
                        currentScore += scores.top();
                        scores.pop();
                    }
                    scores.pop();
                    scores.push(2 * currentScore);
                }
            }
        }
        
        int totalScore = 0;
        while (!scores.empty()) {
            totalScore += scores.top();
            scores.pop();
        }
        
        return totalScore;
    }
};

/*

(((()))())()()()

[0,0,0,0]
[0,0,0,1]
[0,0,]

*/