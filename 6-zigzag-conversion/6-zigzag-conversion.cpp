class Solution {
    int dx[2] = {1, -1};
    int dy[2] = {0, 1};
    
    bool changeDir(int i, int j, int nr) {
        if (i == nr or i < 0 or j < 0) return true;
        return false;
    }
    
public:
    string convert(string s, int nr) {
        if (nr == 1) return s;
        vector<vector<char>> vec(nr, vector<char>(s.size(), 'X'));
        
        int i = 0, j = 0, k = 0, d = 0;
        while (k < s.size()) {
            vec[i][j] = s[k++];

            if (changeDir(i+dx[d], j+dy[d], nr)) {
                if (d == 0) d = 1;
                else d = 0;
            }
            i += dx[d];
            j += dy[d];
           // cout << i << ' ' << j << endl;
        }

        string ans = "";
        for (int p = 0; p < nr; p++) {
            for (int q = 0; q <= j; q++) {
                if (vec[p][q] != 'X') ans += vec[p][q];
            }
        }
        
        return ans;
    }
};