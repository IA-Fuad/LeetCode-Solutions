class Solution {
    const int mod = 1e9 + 7;
    
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> numCount(n, vector<int>(402, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                numCount[j][arr[i]+arr[j]]++;
            }
        }
        
        int ans = 0;
        
        for (int i = 2; i < n; i++) {
            int t = target - arr[i];
            if (t < 0) continue;
            for (int k = 1; k < i; k++) {
                ans += numCount[k][t];
                ans %= mod; 
            }
        }
        
        return ans;
    }
};

/*

1 

*/