class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int k = 0, x = n-1; x > 0; k++, x -= 2) {
            int direction[4][2] = {{0, x}, {x, 0}, {0, -x}, {-x, 0}};
            int nn = n - k;
            
            for (int col = k; col < nn-1; col++) {                  
                int i = k, j = col, curr = matrix[k][col], d = 0;

                while (d < 4) {
                    //cout << i << ' ' << j << ":  ";
                    i += direction[d][0];
                    j += direction[d][1];

                    if (i >= nn) j = j-(i-nn+1), i = nn-1;
                    if (i < k) j = j+(k-i), i = k;
                    if (j >= nn) i = i+(j-nn+1), j = nn-1;
                    if (j < k) i = i-(k-j), j = k;

                    int next = matrix[i][j];
                    matrix[i][j] = curr;
                    curr = next;
                    //cout << i << ' ' << j << endl;
                    d++;
                }
                //cout << endl;
            }
        }
    }
};