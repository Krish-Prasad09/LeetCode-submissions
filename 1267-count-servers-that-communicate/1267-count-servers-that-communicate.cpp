class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int> vecr(row,0);
        vector<int> vecc(col,0);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1){
                    vecr[i]++;
                    vecc[j]++;
                }
            }
        }
        int cnt=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1){
                    bool kara=false;
                    if(vecr[i]>1){
                        kara=true;
                    }
                    if(vecc[j]>1){
                        kara=true;
                    }
                    if(kara) cnt++;
                }
            }
        }
        return cnt;
    }
};