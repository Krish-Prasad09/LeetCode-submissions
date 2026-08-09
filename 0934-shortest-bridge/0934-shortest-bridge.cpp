class Solution {
public:
    void dfs(int indr, int indc, vector<vector<int>>& grid, vector<vector<int>> &vis,int row, int col) {
        vis[indr][indc] = 1;
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newr = delr[i] + indr;
            int newc = delc[i] + indc;
            if (newr < 0 || newc < 0 || newr >= row || newc >= col || vis[newr][newc] || grid[newr][newc]!=1)
                continue;
            dfs(newr,newc,grid,vis,row,col);
        }
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<tuple<int, int, int>> q;
        vector<vector<int>> vis1(row, vector<int>(col,0));
        bool found = false;

        for (int i = 0; i < row && !found; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && !vis1[i][j]) {
                    dfs(i, j, grid, vis1, row, col);
                    found = true;
                    break;
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(vis1[i][j]) q.push({i,j,0});
            }
        }

        vector<vector<int>> vis2(row, vector<int>(col,0));
        int mini=INT_MAX;

        while (!q.empty()) {
            auto [indr, indc, steps] = q.front();
            q.pop();
            if(grid[indr][indc]==1 && vis1[indr][indc]==0){
                mini=min(mini,steps);
                continue;
            }
            int delr[] = {-1, 0, 1, 0};
            int delc[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int newr = delr[i] + indr;
                int newc = delc[i] + indc;
                if (newr < 0 || newc < 0 || newr >= row || newc >= col || vis1[newr][newc]==1 || vis2[newr][newc]==1)
                    continue;
                vis2[newr][newc]=1;
                q.push({newr,newc,steps+1});
            }
        }
        return mini-1;
    }
};