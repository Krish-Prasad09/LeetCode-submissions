const int mod = 1e9 + 7;
class Solution {
public:
    int row, col;
    vector<vector<vector<int>>> dp;

    int dfs(int r, int c, int dir, vector<vector<int>>& grid) {

        if(r == row-1 && c == col-1)
            return 1;

        if(dp[r][c][dir] != -1)
            return dp[r][c][dir];

        int newr1=r+1,newc1=c;
        int newr2=r,newc2=c+1;

        int ans = 0;

        if(grid[r][c] == 1) {

            if(r+1 < row && dir == 1) {
                ans += dfs(r+1,c,2,grid)%mod;
            }
            else if(c+1 < col && dir == 2) {
                ans += dfs(r,c+1,1,grid)%mod;
            }
        }
        else {

            if(newr1 < row) {
                ans += dfs(newr1,newc1,2,grid)%mod;
            }

            if(newc2 < col) {
                ans += dfs(newr2,newc2,1,grid)%mod;
            }
        }

        return dp[r][c][dir] = ans%mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        dp.assign(row, vector<vector<int>>(col, vector<int>(3,-1)));

        return dfs(0,0,0,grid)%mod;
    }
};
