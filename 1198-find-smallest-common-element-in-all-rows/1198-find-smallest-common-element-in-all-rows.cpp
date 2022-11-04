class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int, int> numCount;
        int totalRows = mat.size();
        
        for (auto& row : mat) {
            for (int i = 0; i < row.size(); i++) {
                if (i > 0 and row[i] == row[i-1]) continue;
                numCount[row[i]]++;
                
                if (numCount[row[i]] == totalRows) return row[i];
            }
        }
        
        return -1;
    }
};