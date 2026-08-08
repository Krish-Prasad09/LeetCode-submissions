class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> adjR(n);
        vector<vector<int>> adjB(n);
        for(auto &it:redEdges){
            int u=it[0], v=it[1];
            adjR[u].push_back(v);
        }
        for(auto &it:blueEdges){
            int u=it[0], v=it[1];
            adjB[u].push_back(v);
        }
        queue<tuple<int, int, int>> q;
        q.push({0, -1, 0});
        vector<vector<int>> vis(n, vector<int>(2, 0));
        vis[0][0] = vis[0][1] = 1;
        vector<int> ans(n,-1);

        while(!q.empty()){
            auto [node, color, dist] = q.front();
            q.pop();
            if (ans[node] == -1)
                ans[node] = dist;
            if(true){
                for(auto &it:adjR[node]){
                    if(color==-1 || color==0){
                        if(!vis[it][1]){
                            vis[it][1]=1;
                            q.push({it,1,dist+1});
                        }
                    }
                }
                
            }
            if(true){
                for(auto &it:adjB[node]){
                    if(color==-1 || color==1){
                        if(!vis[it][0]){
                            vis[it][0]=1;
                            q.push({it,0,dist+1});

                        }
                    }
                }
            }
        }

        return ans;
    }
};