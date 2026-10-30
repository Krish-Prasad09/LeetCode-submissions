
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<tuple<int,int,char>>> adj(n);

        for(auto &it:edges){
            int u=it[0],v=it[1],w=it[2];
            adj[u].push_back({v,w,labels[v]});
        }

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > q;

        q.push({0, 0, 1});

        vector<vector<int>> dist(n,vector<int>(k+1,INT_MAX));

        dist[0][1] = 0;

        while(!q.empty()){

            auto [wt,node,cnt]=q.top();
            q.pop();

            if(wt != dist[node][cnt])
                continue;

            if(node==n-1)
                return wt;

            for(auto &it:adj[node]){

                auto [v,w,nch] = it;

                int newCnt;

                if(labels[node] == nch)
                    newCnt = cnt+1;
                else
                    newCnt = 1;

                if(newCnt > k) continue;

                if(wt+w < dist[v][newCnt]){

                    dist[v][newCnt] = wt+w;

                    q.push({wt+w,v,newCnt});
                }
            }
        }

        return -1;
    }
};
