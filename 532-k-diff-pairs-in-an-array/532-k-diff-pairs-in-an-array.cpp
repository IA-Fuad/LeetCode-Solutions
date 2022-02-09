class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        int pairs = 0;
        
        for (int n : nums) {
            auto it = seen.find(n);
            if (it != seen.end()) {
                if (k == 0 && it->second == 1) {
                    pairs++;
                }
                seen[n]++;
                continue;
            }
            it = seen.find(n-k);
            if (it != seen.end()) {
                pairs++;
            }
            it = seen.find(n+k);
            if (it != seen.end()) {
                pairs++;
            }
            seen[n]++;
        }
        
        return pairs;
    }
};