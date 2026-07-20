class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row=grid.size();
        int col=grid[0].size();
        k = k%(row*col);
        vector<vector<int>>ans = grid;
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col  ; j++){
                int ind = i*col + j +k;
                ans[(ind/col)%row][ind%col] = grid[i][j];
            }
        }
         return ans;
    }
};