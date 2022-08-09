class Solution {
    const int mod = 1e9 + 7;
    
    int64_t rec(unordered_map<int, int>& dp, int n) {
        int cnt = 0;
        if (dp.find(n) == dp.end()) return 0;
        if (dp[n] > 0) {
            return dp[n];
        }
        
        //bool isPrime = true;
        int sq = sqrt(n);
        for (int k = 2; k <= sq; k++) {
            if (n % k == 0) {
                int64_t x = ((rec(dp, n / k)%mod) * (rec(dp, k)%mod))%mod;
                if (n/k != k) cnt += ((x + x) % mod);
                else cnt += x;
                cnt %= mod;
                //isPrime = false;
            }
        }
        
        dp[n] = cnt;
        return cnt;
    }
    
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, int> dp;
        sort(arr.begin(), arr.end());
        int cnt = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 0;
            cnt += rec(dp, arr[i]) + 1;
            dp[arr[i]]++;
            
            dp[arr[i]] %= mod;
            cnt %= mod;
          //  cout << arr[i] << ' ' << dp[arr[i]] << endl;
        }
        
        return cnt;
    }
};

/*

3 4 5 6 7 8 9 10 11 12

18 -> (2,9) (3,6) 

*/