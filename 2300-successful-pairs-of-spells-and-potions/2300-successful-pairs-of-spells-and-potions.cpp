class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> pairs;
        
        for (int spell : spells) {
            int left = 0, right = potions.size();
            
            while (left < right) {
                int mid = left + (right - left) / 2;
                int64_t product = (int64_t)potions[mid] * (int64_t)spell;
                
                if (product >= success) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            
            pairs.push_back(potions.size() - right);
        }
        
        return pairs;
    }
};