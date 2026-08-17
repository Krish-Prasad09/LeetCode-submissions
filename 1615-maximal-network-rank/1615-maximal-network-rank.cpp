class Solution {
public:
void dfs(int node,int &num,vector<int>&vis,vector<vector<int>> &adj){
    if(node>=adj.size()) return ;
    vis[node]=1;
    for(auto &it:adj[node]){
        if(!vis[node]){
            num++;
            dfs(it,num,vis,adj);
        }
    }
    return ;
}
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ho=roads.size();
        vector<vector<int>> adj(n);
        for(auto &it:roads){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int maximal = 0;
        for(int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Sum of neighbors (connected cities) of both cities. 
                int network_rank = adj[i].size() + adj[j].size();
                
                // Reduce the rank by 1 in case the cities are connected to each other.
                for(auto x : adj[i]) {
                    if(x == j) {
                        network_rank--;
                        break;
                    }
                }
                
                // Maximal network rank is the maximum network rank possible.
                maximal = max(maximal, network_rank);
            }
            
        }
        return maximal;
    }
};