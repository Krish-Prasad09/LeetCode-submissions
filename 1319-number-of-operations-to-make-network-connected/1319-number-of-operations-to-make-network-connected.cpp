class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    bool find(int u, int v) {
        return findUPar(u) == findUPar(v);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
       int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        DisjointSet ds(n);
        int e=edges.size();
        int extra=0;
        for(auto &it:edges){
            if (ds.findUPar(it[0]) == ds.findUPar(it[1]))
                extra++;
            else
                ds.unionBySize(it[0], it[1]);
        }
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            int p=ds.findUPar(i);
            mp[p]++;
        }
        int collections=mp.size();
        return (extra >= collections - 1) ? (collections - 1) : -1;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        return minEdgesReq(n,connections);
    }
};