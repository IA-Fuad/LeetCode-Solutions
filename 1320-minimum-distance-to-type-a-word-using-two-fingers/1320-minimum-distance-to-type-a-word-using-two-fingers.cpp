class Solution {
    vector<vector<vector<int>>> dp;
    
    int getCharDist(char a, char b) {
        int x1 = (a-'A') / 6, y1 = (a-'A') % 6;
        int x2 = (b-'A') / 6, y2 = (b-'A') % 6; 
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    int rec(const string& word, int kthCharPos, char firstFingerAt, char secondFingerAt) {
        if (word.size() == kthCharPos) return 0;
        
        int& ret = dp[kthCharPos][firstFingerAt-'A'][secondFingerAt-'A'];
        if (ret != -1) return ret;
        
        int moveFirstFinger = rec(word, kthCharPos+1, word[kthCharPos], secondFingerAt) + getCharDist(firstFingerAt, word[kthCharPos]);
        int moveSecondFinger = rec(word, kthCharPos+1, firstFingerAt, word[kthCharPos]) + getCharDist(secondFingerAt, word[kthCharPos]);
        
        return ret = min(moveFirstFinger, moveSecondFinger);
    }
    
public:
    int minimumDistance(string word) {
//         dp.resize(word.size(), vector<vector<int>>(26, vector<int>(26, -1)));
//         int minDist = INT_MAX;

//         for (char c = 'A'; c <= 'Z'; c++) {
//             minDist = min(minDist, rec(word, 0, word[0], c));
//         }
        
        int n = word.size(), ans = INT_MAX;
        dp.resize(n+1, vector<vector<int>>(27, vector<int>(27, 0)));
        
        for (int i = n-1; i >= 0; i--) {
            for (char c1 = 'A'; c1 <= 'Z'; c1++) {
                for (char c2 = 'A'; c2 <= 'Z'; c2++) {
                    int move1 = dp[i+1][word[i]-'A'][c2-'A'] + getCharDist(word[i], c1);
                    int move2 = dp[i+1][c1-'A'][word[i]-'A'] + getCharDist(word[i], c2);
                    dp[i][c1-'A'][c2-'A'] = min(move1, move2);
                    if (i == 0) ans = min(ans, dp[i][c1-'A'][c2-'A']);
                }
            }
        }
        
        return ans;
    }
};

/*

            (1, A1, B2), (1, A1, B3), (1, A1, B4)
        (2, A1, B2)      (2, A2, B2)
(3, A1, B3) (3, A3, B2) (3, A2, B3) (3, A3, B2) -> use memo
        
        
choiceOne = rec(kthChar+1, firstFinger -> kthChar, secondFinger) + (dist between firstFinget and kthChar)
choiceTwo = rec(kthChar+1, firstFinget, secondFinger -> kthChar) + (didt between secondFinger and kthChar)
minDist = min(choiceOne, choiceTwo);

kthChar'c row = floor((kthChar - 'A') / 6)
kthChar's col = (kthChar - 'A') % 6

*/