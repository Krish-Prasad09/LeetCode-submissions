class Solution {
public:
void dfs(int r, int c,vector<vector<int>> &vis, vector<vector<int>>&grid,int row, int col){
    vis[r][c]=1;
    grid[r][c]=1;
    int delr[]={-1,0,1,0};
    int delc[]={0,1,0,-1};
    for(int i=0;i<4; i++){
        int newr=delr[i]+r;
        int newc=delc[i]+c;
        if(newr>=0 && newc>=0  && newr<row && newc<col &&  !vis[newr][newc] && grid[newr][newc]==0){
            dfs(newr,newc,vis,grid,row,col);
        }
    }
    return;
}
    int closedIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        for(int i = 0; i < row; i++) {
            if(grid[i][0] == 0 && !vis[i][0])
                dfs(i, 0, vis, grid, row, col);

            if(grid[i][col-1] == 0 && !vis[i][col-1])
                dfs(i, col-1, vis, grid, row, col);
        }

        for(int j = 0; j < col; j++) {
            if(grid[0][j] == 0 && !vis[0][j])
                dfs(0, j, vis, grid, row, col);

            if(grid[row-1][j] == 0 && !vis[row-1][j])
                dfs(row-1, j, vis, grid, row, col);
        }
        
        int cnt=0;
        for(int i=1; i<row-1; i++){
            for(int j=1; j<col-1; j++){
                if(!vis[i][j] && grid[i][j]==0){
                    dfs(i,j,vis,grid,row,col);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};