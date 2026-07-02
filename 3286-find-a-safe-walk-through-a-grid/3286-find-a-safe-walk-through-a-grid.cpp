class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row = grid.size(), col = grid[0].size();
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        vector<vector<int>>cost(row,vector<int>(col,INT_MIN));
        cost[0][0]=health-grid[0][0];
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({cost[0][0],{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int h=it.first;
            int ri=it.second.first;
            int ci=it.second.second;
            if(h<1) return false;
            if(ri==row-1 && ci==col-1) return true;
            for(int i=0; i<4; i++){
                int newi=delr[i]+ri;
                int newc=delc[i]+ci;
                if(newi>=0 && newc>=0 && newi<row && newc<col){
                    int val=h-grid[newi][newc];
                    if(val>cost[newi][newc]){
                        cost[newi][newc]=val;
                        pq.push({val,{newi,newc}});
                    }
                }
            }
        }
        return false;
    }
};