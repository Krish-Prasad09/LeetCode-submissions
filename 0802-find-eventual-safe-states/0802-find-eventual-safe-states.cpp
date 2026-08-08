class Solution {
public:
bool dfs(int i, vector<vector<int>>& graph,vector<int> &vis,vector<int> &pathVis,vector<int> &safe){
    vis[i]=1;
    pathVis[i]=1;
    for(auto it:graph[i]){
        if(!vis[it]){
            if(dfs(it, graph, vis, pathVis, safe))
                return true;
        }
        else if(pathVis[it]==1) return true;
        else if (!safe[it]) {
                return true;
            }
    }
    pathVis[i] = 0;
        safe[i] = 1;
        return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> safe(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathVis,safe);
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(safe[i]==1) ans.push_back(i);
        }
        return ans;
    }
};