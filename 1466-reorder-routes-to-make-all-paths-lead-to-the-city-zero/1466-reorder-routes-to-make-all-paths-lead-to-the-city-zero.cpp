class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back({it[1],1});
            adj[it[1]].push_back({it[0],0});
        }
        queue<pair<int,int>> q;
        q.push({0,0});  
        vector<int> vis(n,0);vis[0] = 1;
        int cnt=0;
        while(!q.empty()){
            auto topi=q.front();
            q.pop();
            int wt=topi.second;
            int node=topi.first;
            cnt+=wt;
            vis[node]=1;
            for(auto it:adj[node]){
                if(!vis[it.first] || node==0){
                    q.push({it.first,it.second});
                }
            }
        }
        return cnt;
    }
};