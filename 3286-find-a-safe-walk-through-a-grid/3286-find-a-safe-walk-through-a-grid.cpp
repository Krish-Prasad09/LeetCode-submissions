class Solution {
public:
bool f(int ri, int ci, int health, vector<vector<int>> &grid, int row, int col,vector<vector<vector<int>>> &dp){
    if(ri<0 || ci<0 || ri>=row || ci>=col || health<0) return false;
    if(grid[ri][ci]==1) health--;
    if(health<=0) return false;
    if(ri==row-1 && ci==col-1) return true;
    if(dp[ri][ci][health]!=-1) return dp[ri][ci][health];
    int delr[]={-1,0,1,0};
    int delc[]={0,1,0,-1};dp[ri][ci][health] = 0;
    return dp[ri][ci][health]=(f(ri+delr[0],ci+delc[0],health,grid,row,col,dp) || f(ri+delr[1],ci+delc[1],health,grid,row,col,dp) || f(ri+delr[2],ci+delc[2],health,grid,row,col,dp) || f(ri+delr[3],ci+delc[3],health,grid,row,col,dp));
}
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row=grid.size(), col=grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(health + 1, -1)));
        return f(0,0,health,grid,row,col,dp);
    }
};