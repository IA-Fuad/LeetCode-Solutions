class Solution {
    vector<int> dp;
    
    int rec(vector<int>& stoneValue, int i) {
        int len = stoneValue.size();
        
        if (i == len) return 0;
        if (dp[i] != -1) return dp[i];
        
        int a = stoneValue[i] - rec(stoneValue, i+1);
        int b = (i+1) >= len ? INT_MIN : (stoneValue[i] + stoneValue[i+1] - rec(stoneValue, i+2));
        int c = (i+2) >= len ? INT_MIN : (stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - rec(stoneValue, i+3));
       // cout << a << ' ' << b << ' ' << c << endl;
        return dp[i] = max(a, max(b, c));
    }
    
public:
    string stoneGameIII(vector<int>& stoneValue) {
//         dp.resize(stoneValue.size(), -1);
        
//         int diff = rec(stoneValue, 0);
//         // cout << diff << ' ';   
//         if (diff > 0) return "Alice";
//         if (diff < 0) return "Bob";
//         return "Tie";
        
        
        int len = stoneValue.size();
        int currMax[3];
        currMax[0] = 0, currMax[1] = 0, currMax[2] = 0;
        
        for (int i = len-1; i >= 0; i--) {
            int curr = stoneValue[i] - currMax[0];
            curr = max(curr, (i + 1) >= len ? INT_MIN : (stoneValue[i] + stoneValue[i+1] - currMax[1]));
            curr = max(curr, (i + 2) >= len ? INT_MIN : (stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - currMax[2]));
            currMax[2] = currMax[1];
            currMax[1] = currMax[0];
            currMax[0] = curr;
        }
        
        if (currMax[0] > 0) return "Alice";
        if (currMax[0] < 0) return "Bob";
        return "Tie";
    }
};



/**


16 - 14 + 13


**/