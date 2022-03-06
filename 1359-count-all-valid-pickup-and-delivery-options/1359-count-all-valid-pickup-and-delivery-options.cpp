class Solution {
    const int MOD = 1e9 + 7;
    
    int64_t countOrders(int unPicked, int unDelivered, vector<vector<int>>& alreadyCounted) {
        if (unDelivered == 0 and unPicked == 0) return 1;
        if (unDelivered < unPicked or unDelivered < 0 or unPicked < 0) return 0;

        int& counted = alreadyCounted[unPicked][unDelivered];
        
        if (counted != -1) return counted;
        
        int64_t waysToPickUp = (unPicked * countOrders(unPicked - 1, unDelivered, alreadyCounted)) % MOD;
        int64_t waysToDeliver = ((unDelivered - unPicked) * countOrders(unPicked, unDelivered - 1, alreadyCounted)) % MOD;

        return counted = (waysToPickUp + waysToDeliver) % MOD;
    }
    
public:
    int countOrders(int n) {
        // vector<vector<int>> alreadyCounted(n+1, vector<int>(n+1, -1));
        // return countOrders(n, n, alreadyCounted); 
//         for (int unPicked = 0; unPicked <= n; unPicked++) {
//              for (int unDelivered = unPicked; unDelivered <= n; unDelivered++) {
//                 if (unPicked == 0 and unDelivered == 0) {
//                     dp[0][0] = 1;
//                     continue;
//                 } 
                
//                 int64_t waysToPick = unPicked > 0 ? ((int64_t)unPicked * dp[unPicked-1][unDelivered]) % MOD : 0;
//                 int64_t waysToDeliver = unDelivered > unPicked ? ((int64_t)(unDelivered - unPicked) * dp[unPicked][unDelivered-1]) % MOD : 0;

//                 dp[unPicked][unDelivered] = (waysToPick + waysToDeliver) % MOD;
//             }
//         }
        
//         return dp[n][n];
        
        int64_t ans = 1;
        
        for (int i = 1; i <= n; i++) {
            ans = (ans * i) % MOD;
            ans = (ans * ((i * 2) - 1)) % MOD;
        }
        
        return ans;
    }
};

/*

           (1, 1)
            / \
       (1,0) (0,1)-0
          /
       (0,0)


          6-(2, 2)
            /\
         5-(1,2)     
          /\
    2-(0,2) 2-(1, 1)
             /\
      /\  (0,1) 
1-(0,1)
    /
0-(0,0)
*/