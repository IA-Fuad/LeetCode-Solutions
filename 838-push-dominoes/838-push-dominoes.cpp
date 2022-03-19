class Solution {
    void modifyState(string& dominoes, int i, int j, char state) {
        while (i < j) {
            dominoes[i++] = state;
        }
    }
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size(), i, j;
        for (i = 0, j = 0; j < n; j++) {
            if (dominoes[j] != '.') {
                if ((dominoes[i] == '.' and dominoes[j] == 'L') or dominoes[i] == dominoes[j]) {
                    modifyState(dominoes, i, j, dominoes[j]);
                }
                else if (dominoes[i] == 'R' and dominoes[j] == 'L') {
                    int mid = (i+j+1) / 2;
                    int skipMid = (j - i)%2 == 0;
                    modifyState(dominoes, i, mid, dominoes[i]);
                    modifyState(dominoes, mid+skipMid, j, dominoes[j]);
                }
                i = j;
            }
        }
        if (dominoes[j-1] == '.' and dominoes[i] == 'R') {
            modifyState(dominoes, i, j, dominoes[i]);
        }
        return dominoes;
    }
};

/*

.L.R...LR..L..
.L.RRRRLRRRL..
..LLRRLL
*/