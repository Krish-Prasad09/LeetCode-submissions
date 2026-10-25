class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, int row, int col) {
        grid[r][c] = 1;
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newr = r + delr[i];
            int newc = c + delc[i];

            if (newr >= 0 && newc >= 0 && newr < row && newc < col &&
                grid[newr][newc] == 0) {
                dfs(newr, newc, grid, row, col);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            if (grid[i][0] == 0)
                dfs(i, 0, grid, row, col);

            if (grid[i][col - 1] == 0)
                dfs(i, col - 1, grid, row, col);
        }
        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0)
                dfs(0, j, grid, row, col);

            if (grid[row - 1][j] == 0)
                dfs(row - 1, j, grid, row, col);
        }
        int cnt = 0;
        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < col - 1; j++) {
                if (grid[i][j] == 0) {
                    dfs(i, j, grid, row, col);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};