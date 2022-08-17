class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseMap = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> morseWords;
        
        for (const string& word : words) {
            string morse;
            for (char c : word) {
                int x = c - 'a';
                morse += morseMap[x];
            }
            morseWords.insert(morse);
        }
        
        return morseWords.size();
    }
};