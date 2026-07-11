class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            adj[i].push_back(i);
        }
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int m=adj.size();
        int cnt=n-m;
        map<vector<int>,int> mp;
        vector<int> prev;
        for(int i=0; i<m; i++){
            sort(adj[i].begin(),adj[i].end());
            mp[adj[i]]++;
        }
        for(auto &it:mp){
            if(it.first.size()==it.second) cnt++;
        }
        return cnt;

    }
};