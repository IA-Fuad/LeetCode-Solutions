class Solution {
    const int mod = 1e9 + 7;
    
public:
    int countVowelPermutation(int n) {
        vector<int> endsWith(5, 1);
        vector<vector<int>> startsWithChar = {{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}};

        for (int i = 1; i < n; i++) {
            vector<int> currentCharCount(5);
            
            for (int l = 0; l < startsWithChar.size(); l++) {
                for (int k = 0; k < startsWithChar[l].size(); k++) {
                    currentCharCount[startsWithChar[l][k]] += endsWith[l];
                    currentCharCount[startsWithChar[l][k]] %= mod;
                }
            }
            
            endsWith = currentCharCount;
        }
        
        int ans = 0;
        
        for (int x : endsWith) {
            ans += x;
            ans %= mod;
        }
        
        return ans;
    }
};

/*

a = 1
e = 2
i = 4
o = 2
u = 1

*/