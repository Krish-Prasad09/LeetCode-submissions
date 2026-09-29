class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int delr[]={1,0};
        int delc[]={0,1};
        queue<tuple<int,int,int>> q;
        if(grid[0][0] == ')') return false;

        q.push({0,0,1});
        vector<vector<vector<bool>>> vis(
            row, vector<vector<bool>>(col, vector<bool>(row+col+1, false))
        );
        vis[0][0][1] = 1;
        
        while(!q.empty()){
            auto [r,c,balance]=q.front();
            q.pop();
            if(balance<0) continue;
            if(r==row-1 && c==col-1){
                if(balance==0) return true;
                else continue;
            }
            for(int i=0; i<2; i++){
                int newr=delr[i]+r;
                int newc=delc[i]+c;
                if(newr>=0 && newc>=0 && newr<row && newc<col){
                    if(grid[newr][newc]=='(' && vis[newr][newc][balance+1]!=1){
                        q.push({newr,newc,balance+1});
                        vis[newr][newc][balance+1]=1;
                    } 
                    else if(grid[newr][newc]==')' && balance-1>=0 && vis[newr][newc][balance-1]!=1){
                        q.push({newr,newc,balance-1});
                        vis[newr][newc][balance-1]=1;
                    } 
                }
            }
        }
        return false;
    }
};