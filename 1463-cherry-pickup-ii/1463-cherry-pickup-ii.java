class Solution {
    public int cherryPickup(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][][] dpCache = new int[m][n][n];
        // initial all elements to -1 to mark unseen
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dpCache[i][j][k] = -1;
                }
            }
        }
        return dp(0, 0, n - 1, grid, dpCache);
    }

    private int dp(int row, int col1, int col2, int[][] grid, int[][][] dpCache) {
        if (row == grid.length || col1 < 0 || col1 >= grid[0].length || col2 < 0 || col2 >= grid[0].length) {
            return 0;
        }
        // check cache
        if (dpCache[row][col1][col2] != -1) {
            return dpCache[row][col1][col2];
        }
        // current cell
        int max = 0;
        // transition
        for (int newCol1 = col1 - 1; newCol1 <= col1 + 1; newCol1++) {
            for (int newCol2 = col2 - 1; newCol2 <= col2 + 1; newCol2++) {
                int totalSum = dp(row + 1, newCol1, newCol2, grid, dpCache) + grid[row][col1];
                if (col1 != col2) {
                    totalSum += grid[row][col2];
                }
                max = Math.max(max, totalSum);
            }
        }
        dpCache[row][col1][col2] = max;
        return max;
    }
}