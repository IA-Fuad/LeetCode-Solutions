class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> diagonalKeyToIndex;
        vector<pair<int, int>> numsAndKey;
        int m = mat.size(), n = mat[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int key = i - j;
                if (diagonalKeyToIndex.find(key) == diagonalKeyToIndex.end()) {
                    diagonalKeyToIndex[key] = {i, j};
                }
                numsAndKey.push_back({mat[i][j], key});
            }
        }
        
        sort(numsAndKey.begin(), numsAndKey.end());
        
        vector<vector<int>> diagonalSortedMat(m, vector<int>(n));
        
        for (auto[num, key] : numsAndKey) {
            auto it = diagonalKeyToIndex.find(key);
            auto[i, j] = it->second;

            diagonalSortedMat[i][j] = num;
            
            it->second.first++;
            it->second.second++;
        }
        
        return diagonalSortedMat;
    }
};