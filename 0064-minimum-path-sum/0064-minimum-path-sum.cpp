class Solution {
public:
    int f(int r, int c, vector<vector<int>> &grid,
          vector<vector<int>> &dp) {

        if(r >= grid.size() || c >= grid[0].size())
            return INT_MAX;

        if(r == grid.size()-1 && c == grid[0].size()-1)
            return grid[r][c];

        if(dp[r][c] != -1)
            return dp[r][c];

        int rig = f(r, c+1, grid, dp);
        int dow = f(r+1, c, grid, dp);

        if(rig != INT_MAX)
            rig += grid[r][c];

        if(dow != INT_MAX)
            dow += grid[r][c];

        return dp[r][c] = min(rig, dow);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(0, 0, grid, dp);
    }
};