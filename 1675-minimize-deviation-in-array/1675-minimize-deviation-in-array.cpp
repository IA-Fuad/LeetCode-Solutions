class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            int k = nums[i];
            if (k&1) {
                vec.push_back({k, i});
                vec.push_back({k*2, i});
            }
            else {
                while (k && k%2 == 0) {
                    vec.push_back({k, i});
                    k /= 2;
                }
                vec.push_back({k, i});
            }
        }
        sort(vec.begin(), vec.end());
        
        unordered_map<int, int> mark;
        
        for (int i = 0, j = 0, k = 0; j < vec.size(); j++) {
            auto it = mark.find(vec[j].second);
            if (it == mark.end()) {
                k++;
            }
            mark[vec[j].second]++;
            
            while (i < j && mark[vec[i].second] > 1) {
                mark[vec[i].second]--;
                i++;
            }
            
            if (k == n) {
                ans = min(ans, vec[j].first - vec[i].first);
            }
        }
        
        return ans;
    }
};