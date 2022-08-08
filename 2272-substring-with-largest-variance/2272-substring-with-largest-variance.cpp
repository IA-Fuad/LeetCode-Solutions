class Solution {
public:
    int largestVariance(string s) {
        int maxDiff = 0;
        
        unordered_set<char> uniqueChar(s.begin(), s.end());
        
        for (char c : uniqueChar) {
            for (char d : uniqueChar) {
                if (c == d) continue;
                //cout << c << ' ' << d << endl;
                int currentDiff = 0;
                int cCount = 0, dCount = 0;
                
                for (int i = 0, j = 0; i < s.size(); i++) {
                    if (s[i] != c and s[i] != d) continue;
                    cCount += (s[i] == c ? 1 : 0);
                    dCount += (s[i] == d ? 1 : 0);
                    
                    while (dCount >= cCount and j < i) {
                        cCount -= (s[j] == c ? 1 : 0);
                        dCount -= (s[j] == d ? 1 : 0);
                        j++;
                    }
                    
                    if (cCount > 0 and dCount > 0) {
                        maxDiff = max(maxDiff, cCount - dCount);
                    }
                    
                    //cout << cCount << ' ' << dCount << endl;
                }
                cCount = dCount = currentDiff = 0;
                for (int i = 0, j = 0; i < s.size(); i++) {
                    if (s[i] != c and s[i] != d) continue;
                    cCount += (s[i] == c ? 1 : 0);
                    dCount += (s[i] == d ? 1 : 0);
                    
                    while (dCount > cCount and j < i) {
                        cCount -= (s[j] == c ? 1 : 0);
                        dCount -= (s[j] == d ? 1 : 0);
                        j++;
                    }
                    
                    if (cCount > 0 and dCount > 0) {
                        maxDiff = max(maxDiff, cCount - dCount);
                    }
                    
                    //cout << cCount << ' ' << dCount << endl;
                }
                //cout << endl;
            }
        }
        
        return maxDiff;
    }
};

/*


-1 -1 1 -1 1 1 1

-1 -1 1 

a = 1, b = 0
a = 2, b = 0
a = 2, b = 1
a = 3, b = 1
a = 3, b = 2
a = 3, b = 3
a = 3, b = 4

*/