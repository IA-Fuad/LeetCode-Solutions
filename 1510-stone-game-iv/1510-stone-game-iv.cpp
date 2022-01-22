class Solution {
    vector<int> squares;
    vector<int> isWinningComb;
    
    bool rec(int n, bool alice) {
        if (n == 0) return false;
        if (isWinningComb[n] != -1) return isWinningComb[n] == 1 ? true : false;
        
        bool win = false;
        for (int i = 0; i < squares.size(); i++) {
            if (squares[i] > n) break;
            win |= (!rec(n - squares[i], !alice));
        }
        //cout << n << ' ' << win << ' ' << move << endl;
        return isWinningComb[n] = win;
    }
    
public:
    bool winnerSquareGame(int n) {
        for (int i = 1; i * i <= n; i++) squares.push_back(i * i);
        isWinningComb.resize(n+1, -1);
        
        return rec(n, true);
    }
};