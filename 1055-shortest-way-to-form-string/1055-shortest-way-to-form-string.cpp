class Solution {
public:
    int shortestWay(string source, string target) {
        int subSeqNeeded = 1, ss = source.size(), ts = target.size();
        vector<vector<int>> charIndices(ss, vector<int>(26,-1));
        
        for (int i = ss-1; i >= 0; i--) {
            if (i == ss-1) {
                charIndices[i][source[i]-'a'] = i;
                continue;
            }
            for (int j = 0; j < 26; j++) {
                charIndices[i][j] = charIndices[i+1][j];
            }
            charIndices[i][source[i]-'a'] = i;
        }
        
        for (int i = 0, k = 0; i < ts; i++) {
            int c = target[i] - 'a';
            if (charIndices[0][c] == -1) return -1;
            
            if (k == ss) {
                subSeqNeeded++;
                k = 0;
            }
            else if (charIndices[k][c] == -1) {
                subSeqNeeded++;
                k = 0;
            }
            
            k = charIndices[k][c] + 1;
        }
        
        return subSeqNeeded;
    }
};