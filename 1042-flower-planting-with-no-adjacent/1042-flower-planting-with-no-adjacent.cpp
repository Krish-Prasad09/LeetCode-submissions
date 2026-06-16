class Solution {
public: 
vector<int> ans;
int V;
bool isSafe(int node, vector<int> adj[], vector<int> &color, int c) {
    // Only iterate through actual neighbors
    for (auto neighbor : adj[node]) {
        if (color[neighbor] == c) {
            return false; // Found a neighbor with the same color
        }
    }
    return true;
}

    bool solve(int node,vector<int> adj[], vector<int>&color, int c,int m){
        if(node>=V) return true;
        for(int col=1; col<=m; col++){
            if(isSafe(node,adj,color,col)){
                color[node]=col;
                if(solve(node+1,adj,color,c,m)){
                    ans=color;
                    return true;
                }
                color[node]=-1;
            }
            
        }
        return false;
        
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        int e=edges.size();
        V=v;
        vector<int> adj[v];
        for (auto it : edges) {
            adj[it[0]-1].push_back(it[1]-1);
adj[it[1]-1].push_back(it[0]-1); // Because it is an undirected graph
        }
        vector<int> color(V,-1);
        int c=0;
        return solve(0,adj,color,c,m);
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        if(graphColoring(n,paths,4)){
            return ans;
        }
        return {};
    }
};