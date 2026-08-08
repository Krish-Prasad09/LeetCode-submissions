class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<n; i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back({i, informTime[manager[i]]});
            }
        }
        queue<pair<int,int>> q;
        q.push({headID,0});
        int maxi=0;
        while(!q.empty()){
            auto [node,time]=q.front();
            q.pop();
            maxi=max(maxi,time);
            for(auto &it:adj[node]){
                q.push({it.first,time+it.second});
            }
        }
        return maxi;
    }
};