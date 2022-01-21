class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int i = 0, j = 0, currentTotalGas = 0; j < n * 2; j++) {
            if (currentTotalGas < 0) {
                currentTotalGas = 0;
                i = j;
            }
            int y = j % n;
            
            currentTotalGas += (gas[y] - cost[y]);
            
            while ((currentTotalGas < 0 && i < j) || j - i >= n) {
                int x = i % n;
                currentTotalGas -= (gas[x] - cost[x]);
                i++;
            }
            
            if (j - i == n - 1 && currentTotalGas >= 0) return i;
        }
        
        return -1;
    }
};