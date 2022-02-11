class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), longestLineLength = 0;
        vector<vector<int>> lineLengths(n+2, vector<int>(4,0));
        
        for (int i = 0; i < m; i++) {
            int prevDiagonal = 0;
            for (int j = 1; j <= n; j++) {
                int tempDiagonal = lineLengths[j][2];
                if (mat[i][j-1] == 1) {
                    lineLengths[j][0] = lineLengths[j-1][0] + 1;
                    lineLengths[j][1] = lineLengths[j][1] + 1;
                    lineLengths[j][2] = prevDiagonal + 1;
                    lineLengths[j][3] = lineLengths[j+1][3] + 1;
                }
                else {
                    lineLengths[j][0] = lineLengths[j][1] = lineLengths[j][2] = lineLengths[j][3] = 0;
                }
                longestLineLength = max(longestLineLength, *max_element(lineLengths[j].begin(), lineLengths[j].end()));
                prevDiagonal = tempDiagonal;
            }
        }
        
        return longestLineLength;
    }
};