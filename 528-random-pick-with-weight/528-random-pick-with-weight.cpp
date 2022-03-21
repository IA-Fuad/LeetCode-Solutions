class Solution {
    vector<int> prefixSum;
    
public:
    Solution(vector<int>& w) {
        prefixSum.resize(w.size());
        prefixSum[0] = w[0];
        for (int i = 1; i < w.size(); i++) {
            prefixSum[i] = prefixSum[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        int randomNum = rand() % prefixSum.back() + 1;
        return lower_bound(prefixSum.begin(), prefixSum.end(), randomNum) - prefixSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */


/*

0 0 1 1 1 1 2 3 3 3 3 3 4 4 4

2 6 7 12 15

*/
