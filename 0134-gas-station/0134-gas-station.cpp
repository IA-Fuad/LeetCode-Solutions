class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int left = 0, right = 0, currentGas = 0;
        
        while (right < n * 2) {
            currentGas = (currentGas + gas[right % n] - cost[right % n]);
            
            //cout << currentGas << ' ' << left << ' ' << right << endl;
            
            if (currentGas >= 0 and right - left == n) {
                return left;
            }
            
            while (currentGas < 0 and left <= right) {
                currentGas = (currentGas - gas[left % n] + cost[left % n]);
                left++;
            }
            
            right++;
        }
        
        return -1;
    }
};