class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> charCount(26, 0);
        vector<int> isInStack(26, false);
        stack<char> smallestLexiOrder;
        
        for (char c : s) {
            charCount[c-'a']++;
        }
        
        for (char c : s) {
            if (smallestLexiOrder.empty()) smallestLexiOrder.push(c);
            else if (isInStack[c-'a']) {
                charCount[c-'a']--;
            }
            else {
                while (!smallestLexiOrder.empty() and smallestLexiOrder.top() >= c and charCount[smallestLexiOrder.top()-'a'] > 1) {
                    int cc = smallestLexiOrder.top()-'a';
                    charCount[cc]--;
                    isInStack[cc] = false;
                    smallestLexiOrder.pop();
                }
                smallestLexiOrder.push(c);
            }
            isInStack[c-'a'] = true;
        }
        
        string distinctLetters;
        while (!smallestLexiOrder.empty()) {
            char c = smallestLexiOrder.top();
            if (charCount[c-'a'] == 1) distinctLetters.push_back(c);
            charCount[c-'a']--;
            smallestLexiOrder.pop();
        }
        reverse(distinctLetters.begin(), distinctLetters.end());
        
        return distinctLetters;
    }
};

/*

cbacdcbc
acdb

abc

*/