class Solution {
    const int MOD = 1e9 + 7;
    
    int64_t countOrders(int unPicked, int unDelivered, vector<vector<int>>& alreadyCounted) {
        if (unDelivered == 0 and unPicked == 0) return 1;
        if (unDelivered < unPicked or unDelivered < 0 or unPicked < 0) return 0;

        int& counted = alreadyCounted[unPicked][unDelivered];
        
        if (counted != -1) return counted;
        
        int64_t waysToPickUp = (unPicked * countOrders(unPicked - 1, unDelivered, alreadyCounted)) % MOD;
        int64_t waysToDeliver = ((unDelivered - unPicked) * countOrders(unPicked, unDelivered - 1, alreadyCounted)) % MOD;

        counted = (waysToPickUp + waysToDeliver) % MOD;
        
        return counted;
    }
    
public:
    int countOrders(int n) {
        vector<vector<int>> alreadyCounted(n+1, vector<int>(n+1, -1));
        return countOrders(n, n, alreadyCounted);
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