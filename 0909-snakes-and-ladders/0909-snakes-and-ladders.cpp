class Solution {
    pair<int, int> getIndex(int n, int label) {
        int row = n - ((label+n-1) / n), col;
        if ((n % 2 == 0 and row % 2 == 0) or (n&1 and row&1)){ 
            col = (label % n);
            col = col != 0 ? n - col : col;
        }
        else {
            col = (label % n);
            col = col != 0 ? col - 1 : n - 1;
        }
        return {row, col};
    }
    
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int N = n * n;
        queue<pair<int, int>> cells;
        vector<bool> isVis(N+1, false);
        
        cells.push({1, 0});
        isVis[1] = true;
        
        while (!cells.empty()) {
            auto[curr, move] = cells.front();
            cells.pop();
            
            for (int k = 1; k <= 6; k++) {
                int next = curr + k;
                auto[ni, nj] = getIndex(n, next);
                if (board[ni][nj] != -1) {
                    next = board[ni][nj];
                }
                if (next == N) {
                    //cout << curr << ' ' << k << ' ' << ni << ' ' << nj << endl;
                    return move + 1;
                }
                if (!isVis[next]) {
                    isVis[next] = true;
                    cells.push({next, move + 1});
                }
            }
        }
        
        return -1;
    }
};