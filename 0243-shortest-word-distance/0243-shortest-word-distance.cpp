class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size(), minDist = n, w1i = -1, w2i = -1;
        
        for (int i = 0; i < n; i++) {
            if (wordsDict[i] == word1) w1i = i;
            else if (wordsDict[i] == word2) w2i = i;
            
            if (w1i != -1 and w2i != -1) {
                minDist = min(minDist, abs(w1i - w2i));
            }
        }
        
        return minDist;
    }
};