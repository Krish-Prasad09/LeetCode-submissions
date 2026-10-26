class Solution {
public:
int cnt=0;
void dfs(int r, int c, long long &sum,vector<vector<int>>& grid, int k){
    sum+=grid[r][c];
    grid[r][c]=0;
    int delr[]={-1,0,1,0};
    int delc[]={0,1,0,-1};
    for(int i=0; i<4; i++){
        int newr=delr[i]+r;
        int newc=delc[i]+c;
        if(newr>=0 && newc>=0 && newr<grid.size() && newc<grid[0].size() && grid[newr][newc]!=0){
            dfs(newr,newc,sum,grid,k);
        }
    }
}
    int countIslands(vector<vector<int>>& grid, int k) {
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]!=0){
                    long long sumo=0;
                    dfs(i,j,sumo,grid,k);
                    if(sumo%k ==0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};