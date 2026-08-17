class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n + 1, 0);
        for(auto &it:trust){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        for(int i=1; i<=n; i++){
            if(adj[i].size()==0 && indegree[i] == n-1) return i;
        }
        return -1;
    }
};