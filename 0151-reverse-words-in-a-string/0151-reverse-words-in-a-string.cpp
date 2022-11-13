class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        stack<string> words;
        string word;
        
        while (ss >> word) {
            if (word == " ") continue;
            words.push(word);
        }
        
        string reversedWords;
        
        while (!words.empty()) {
            reversedWords += words.top();
            reversedWords += ' ';
            words.pop();
        }
        reversedWords.pop_back();
        
        return reversedWords;
    }
};