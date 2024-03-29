class Solution {
    int rec(vector<int>& arr, vector<vector<int>>& dp, int l, int r) {
        if (l >= r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        
        int ans = INT_MAX;
        for (int k = l; k < r; k++) {
            int maxFromLeft = INT_MIN, maxFromRight = INT_MIN;
            for (int i = l; i <= k; i++) maxFromLeft = max(maxFromLeft, arr[i]);
            for (int i = k+1; i <= r; i++) maxFromRight = max(maxFromRight, arr[i]);
            ans = min(ans, maxFromLeft*maxFromRight + rec(arr, dp, l, k) + rec(arr, dp, k+1, r));
        }
        return dp[l][r] = ans;
    }
    
public:
    int mctFromLeafValues(vector<int>& arr) {
//        int n = arr.size();
//         vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
//         //int x = rec(arr, dp, 0, arr.size()-1);
//         //return x;
//         for (int l = n-1; l >= 0; l--) {
//             dp[l][l] = 0;
//             for (int r = l; r < n; r++) {
//                 for (int k = l; k < r; k++) {
//                     int maxFromLeft = INT_MIN, maxFromRight = INT_MIN;
//                     for (int i = l; i <= k; i++) maxFromLeft = max(maxFromLeft, arr[i]);
//                     for (int i = k+1; i <= r; i++) maxFromRight = max(maxFromRight, arr[i]);
//                     dp[l][r] = min(dp[l][r], maxFromLeft*maxFromRight + dp[l][k] + dp[k+1][r]);
//                     //cout << l << ' ' << k << ' ' << r << endl;
//                 }
//                 cout << dp[l][r] << ' ';
//             }
//             cout << endl;
//         }
        
//         return dp[0][n-1];
        int ans = 0;
        stack<int> nums;
        
        for (int n : arr) {
            while (!nums.empty() && nums.top() <= n) {
                int curr = nums.top();
                nums.pop();
                int prev = nums.empty() ? INT_MAX : nums.top();
                ans += (curr * min(prev, n));
            }
            nums.push(n);
        }
        
        while (nums.size() > 1) {
            int curr = nums.top();
            nums.pop();
            ans += curr * nums.top();
        }
        
        return ans;
    }
};