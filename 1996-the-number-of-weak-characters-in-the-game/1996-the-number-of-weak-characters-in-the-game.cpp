class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.rbegin(), properties.rend());
        
        int maxDef = 0, tempMax = properties[0][1], ans = 0;
        
        for (int i = 1; i < properties.size(); i++) {
            auto& curr = properties[i], prev = properties[i-1];

            if (curr[0] != prev[0]) {
                maxDef = max(maxDef, tempMax);
                tempMax = 0;
            }
            tempMax = max(tempMax, curr[1]);
            
            if (maxDef > curr[1]) {
                ans++;
            }
        }
        
        return ans;
    }
};