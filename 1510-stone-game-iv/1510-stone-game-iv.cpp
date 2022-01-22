class Solution {
    vector<int> squares;
    vector<int> isWinningComb;
    
    bool rec(int n, bool alice) {
        if (n == 0) return !alice;
        if (isWinningComb[n] != -1) return isWinningComb[n] == 1 ? true : false;
        
        bool win = false;
        for (int i = 0; i < squares.size(); i++) {
            if (squares[i] > n) break;
            win |= (rec(n - squares[i], !alice));
        }
        //cout << n << ' ' << win << ' ' << move << endl;
        return isWinningComb[n] = win && alice;
    }
    
public:
    bool winnerSquareGame(int n) {
        for (int i = 1; i * i <= n; i++) squares.push_back(i * i);
        //isWinningComb.resize(n+1, -1);
        //return rec(n, true);
        
        vector <bool> dp(n+1);
        dp[0] = false;
        
        for (int i = 1; i <= n; i++) {
            bool win = false;
            for (int k = 0; k < squares.size(); k++) {
                if (squares[k] > i) break;
                if (!dp[i - squares[k]]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};