class Solution {
    const int dir[4][2] = {{-1, 1}, {1, -1}, {0, 1}, {1, 0}};
    const int upDiag = 0;
    const int downDiag = 1;
    const int right = 2;
    const int down = 3;
    
    bool isOutOfBound(int m, int n, int i, int j) {
        return i < 0 or j < 0 or i >= m or j >= n;
    }
    
    int getNextDir(int m, int n, bool goingUp, int i, int j) {
        if (goingUp) {
            if (isOutOfBound(m, n, i+dir[right][0], j+dir[right][1])) {
                return down;
            }
            return right;
        }
        if (isOutOfBound(m, n, i+dir[down][0], j+dir[down][1])) {
            return right;
        }
        return down;
    }
    
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i = 0, j = 0, m = mat.size(), n = mat[0].size();
        bool goingUp = true;
        int currDir = upDiag;
        vector<int> elements;
        
        while (i != m and j != n) {
            elements.push_back(mat[i][j]);
            
            bool directionChanged = false;
            if (isOutOfBound(m, n, i + dir[currDir][0], j + dir[currDir][1])) {
                currDir = getNextDir(m, n, goingUp, i, j);
                goingUp = !goingUp;
            }
            
            i += dir[currDir][0];
            j += dir[currDir][1];
            
            currDir = goingUp ? upDiag : downDiag;
        }
        
        return elements;
    }
};


/*

upDiag -> right/down -> downDiag -> down/right

*/