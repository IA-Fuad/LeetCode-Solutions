class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ms = INT_MAX, n = cardPoints.size(), kk = n - k, totalScore = 0;
        //cout << kk << ' ';
        for (int i = 0, j = 0, currentScore = 0; j < n; j++) {
            currentScore += cardPoints[j];
            if (kk > 0 and j >= kk-1) {
                ms = min(ms, currentScore);
                currentScore -= cardPoints[i++];
            }

            totalScore += cardPoints[j];
            
            //cout << ms << endl;
        }
        
        return ms == INT_MAX ? totalScore : totalScore - ms;
    }
};