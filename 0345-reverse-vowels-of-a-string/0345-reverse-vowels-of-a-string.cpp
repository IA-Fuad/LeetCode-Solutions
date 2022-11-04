class Solution {
    bool isVowel(char c) {
        char cc = tolower(c);
        return (cc == 'a' or cc == 'e' or cc == 'i' or cc == 'o' or cc == 'u');
    }
public:
    string reverseVowels(string s) {
        for (int i = 0, j = s.size()-1; i < j; ) {
            if (isVowel(s[i]) and isVowel(s[j])) {
                swap(s[i], s[j]);
                i++, j--;
            }
            else if (!isVowel(s[i])) {
                i++;
            }
            else {
                j--;
            }
        }
        
        return s;
    }
};