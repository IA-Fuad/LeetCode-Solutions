class Solution {
    const int mod = 1e9 + 7;
    
public:
    int countPalindromes(string s) {
        int n = s.size();
        vector<vector<int>> leftDigitCount(n, vector<int>(10, 0));
        vector<vector<int>> rightDigitCount(n, vector<int>(10, 0));
        vector<vector<vector<int64_t>>> leftPairCount(n, vector<vector<int64_t>>(10, vector<int64_t>(10, 0)));
        vector<vector<vector<int64_t>>> rightPairCount(n, vector<vector<int64_t>>(10, vector<int64_t>(10, 0)));
        
        leftDigitCount[0][s[0]-'0'] = rightDigitCount[n-1][s[n-1]-'0'] = 1;
        for (int i = 1, j = n-2; i < n-1; i++, j--) {
            int digitI = s[i] - '0';
            int digitJ = s[j] - '0';
            
            for (int x = 0; x < 10; x++) {
                for (int y = 0; y < 10; y++) {
                    leftPairCount[i][x][y] = leftPairCount[i-1][x][y];
                    rightPairCount[j][x][y] = rightPairCount[j+1][x][y];
                }
                leftDigitCount[i][x] = leftDigitCount[i-1][x];
                rightDigitCount[j][x] = rightDigitCount[j+1][x];
            }
            
            for (int k = 0; k < 10; k++) {
                leftPairCount[i][k][digitI] += leftDigitCount[i-1][k];
                rightPairCount[j][digitJ][k] += rightDigitCount[j+1][k];
                leftPairCount[i][k][digitI] %= mod;
                rightPairCount[j][digitJ][k] %= mod;
            }
            leftDigitCount[i][digitI] = (leftDigitCount[i-1][digitI] + 1) % mod;
            rightDigitCount[j][digitJ] = (rightDigitCount[j+1][digitJ] + 1) % mod;
        }
        
        int palindrome = 0;
        
        for (int i = 2; i < n-2; i++) {
            for (int x = 0; x < 10; x++) {
                for (int y = 0; y < 10; y++) {
                    palindrome += ((leftPairCount[i-1][x][y] * rightPairCount[i+1][y][x]) % mod);
                    palindrome %= mod;
                }
            }
        }
        
        return palindrome;
    }
};


/*

0000000

00 0 0000
000 0 000
0000 0 00


*/