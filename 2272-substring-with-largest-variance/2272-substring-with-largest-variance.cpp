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
                int cCount = 0, dCount = 0, prevCCount = 0, prevDCount = 0;
                
                for (int i = 0, j = 0; i < s.size(); i++) {
                    if (s[i] != c and s[i] != d) continue;
                    cCount += (s[i] == c ? 1 : 0);
                    dCount += (s[i] == d ? 1 : 0);
                    
                    if (dCount >= cCount) {
                        prevCCount = cCount;
                        prevDCount = dCount;
                        cCount = dCount = 0;
                    }
                    
                    if (cCount > 0 and dCount > 0) {
                        maxDiff = max(maxDiff, cCount - dCount);
                    }
                    else if (cCount+prevCCount > 0 and dCount+prevDCount > 0) {
                        maxDiff = max(maxDiff, (cCount+prevCCount)-(dCount+prevDCount));
                    }
                    //cout << cCount << ' ' << dCount << endl;
                }
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