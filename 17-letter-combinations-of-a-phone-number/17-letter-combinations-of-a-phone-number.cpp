class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        
        vector<string> digitToLetterMapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        queue<string> Q;
        
        for (char c : digitToLetterMapping[digits[0]-'2']) {
            Q.push(string(1, c));
        }
        
        vector<string> letterCombs;
        int digit = 1;
        
        while (digit < digits.size()) {
            int currentLevelSize = Q.size();

            for (int i = 0; i < currentLevelSize; i++) {
                string currentComb = Q.front();
                Q.pop();

                for (char c : digitToLetterMapping[digits[digit]-'2']) {
                    Q.push(currentComb+c);
                }
            }
            digit++;
        }
        
        while (!Q.empty()) {
            letterCombs.push_back(Q.front());
            Q.pop();
        }
        
        return letterCombs;
    }
};

/*

[2] = abc
[3] = def

  a      b      c
d e f  d e f  d e f

ad ae af

*/