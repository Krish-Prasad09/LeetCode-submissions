class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int mini=INT_MAX;
        queue<tuple<int,int,int>>q;
        
        // 1. Create a 3D visited array tracking [row][col][current_xor]
        vector<vector<vector<bool>>> vis(row, vector<vector<bool>>(col, vector<bool>(1024, false)));
        
        q.push({0,0,grid[0][0]});
        vis[0][0][grid[0][0]] = true; // 2. Mark initial state as visited
        
        while(!q.empty()){
            auto [r,c,xoro]=q.front();
            q.pop();
            if(r==row-1 && c==col-1){
                mini=min(mini,xoro);
            }
            int delr[]={1,0};
            int delc[]={0,1};
            for(int i=0; i<2; i++){
                int newr=r+delr[i];
                int newc=c+delc[i];
                // Note: Fixed the single '&' to '&&' here
                if(newr>=0 && newc>=0 && newr<row && newc<col){
                    int next_xor = xoro ^ grid[newr][newc];
                    
                    // 3. Only push to queue if this exact state hasn't been seen before
                    if(!vis[newr][newc][next_xor]) {
                        vis[newr][newc][next_xor] = true;
                        q.push({newr, newc, next_xor});
                    }
                }
            }
        }
        return mini;
    }
};