class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> amounts(query_row+2, 0);
        amounts[0] = poured;
        
        for (int i = 1; i <= query_row; i++) {
            vector<double> currentRow(query_row+2, 0);
            
            if (amounts[0] > 1) currentRow[0] = (amounts[0] - 1) / 2.0;
            for (int j = 1; j <= i; j++) {
                if (amounts[j-1] > 1) currentRow[j] = (amounts[j-1] - 1) / 2.0;
                if (amounts[j] > 1) currentRow[j] += (amounts[j] - 1) / 2.0;
            }
            
            amounts = currentRow;
        }
        
        return amounts[query_glass] > 1.0 ? 1.0 : amounts[query_glass];
    }
};