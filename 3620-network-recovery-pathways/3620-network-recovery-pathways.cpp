#define ll long long
class Solution {
public:
bool check(ll mid, vector<vector<pair<int,int>>> &adj, vector<int>& topo, vector<bool> &online, ll k, int n){
    const ll INF=1e18;
    vector<ll> dist(n,INF);
    dist[0]=0;
    for(int u:topo){
        if(dist[u]==INF) continue;
        if(u!=0 && u!=n-1 && !online[u]) continue;

        for(auto &[v,w]:adj[u]){
            if(w<mid) continue;
            if(v!=n-1 && !online[v]) continue;

            dist[v]=min(dist[v],dist[u]+w);
        }
    }
    return dist[n-1]<=k;
}
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n, 0);
        int mx=0;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v, wt});
            indegree[v]++;
            mx=max(mx,wt);
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            topo.push_back(u);

            for(auto &[v,w]:adj[u]){
                if(--indegree[v]==0) q.push(v);
            }
        }
        ll low=0, high=mx, ans=-1;
        while(low<=high){
            ll mid=(low+high)/2;
            if(check(mid,adj,topo,online,k,n)){
                ans=mid;low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};