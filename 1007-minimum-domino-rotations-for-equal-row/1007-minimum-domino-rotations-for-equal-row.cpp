class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<vector<pair<int, int>>> rotationInfo(2, vector<pair<int, int>>(7, {0, 0}));
        
        for (int i = 0; i < n; i++) {
            rotationInfo[0][tops[i]].first++;
            rotationInfo[1][bottoms[i]].first++;
            
            if (tops[i] != bottoms[i]) {
                rotationInfo[0][bottoms[i]].first++;
                rotationInfo[1][tops[i]].first++;
                rotationInfo[0][bottoms[i]].second++;
                rotationInfo[1][tops[i]].second++;
            }
        }
        
        int minRotation = INT_MAX;
        
        for (int i = 1; i <= 6; i++) {
            auto[topICount, topIRotation] = rotationInfo[0][i];
            auto[bottomICount, bottomIRotation] = rotationInfo[1][i];
            
            if (topICount == n) {
                minRotation = min(minRotation, topIRotation);
            }
            if (bottomICount == n) {
                minRotation = min(minRotation, bottomIRotation);
            }
        }
        
        return minRotation == INT_MAX ? -1 : minRotation;
    }
};

/*

[2,1,2,4,2,2]
[5,2,6,2,3,2]


rot1 -> [1] = 0

*/