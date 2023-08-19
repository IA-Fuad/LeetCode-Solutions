class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> leftInc(n, 1);
        
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) leftInc[i] = leftInc[i-1] + 1;
        }
        
        int rightInc = 1, minCandy = 0;
        for (int i = n-1; i >= 0; i--) {
            if (i < n-1 and ratings[i] > ratings[i+1]) rightInc++;
            else rightInc = 1;
            
            minCandy += max(leftInc[i], rightInc);
        }
        
        return minCandy;
    }
};