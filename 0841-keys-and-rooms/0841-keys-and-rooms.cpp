class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                adj[i].push_back(rooms[i][j]);
                // adj[rooms[i][j]].push_back(i);
            }
        }
        queue<int> q;
        vector<int> visited(n,0);
        q.push(0);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            visited[node]=1;
            for(auto &it:adj[node]){
                if(visited[it]!=1) q.push(it);
            }
        }
        for(auto &it : visited){
            if(it==0) return false;
        }
        return true;
    }
};