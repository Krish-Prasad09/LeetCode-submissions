class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < equations.size(); i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        vector<double> ans;
        for (auto &query : queries) {
            if (!adj.count(query[0]) || !adj.count(query[1])) {
                ans.push_back(-1.0);
                continue;
            }
            queue<pair<string,double>> q;
            unordered_set<string> vis;
            q.push({query[0], 1.0});
            bool found = false;
            while(!q.empty()){
            auto topi=q.front();
            q.pop();
            double wt=topi.second;
            string node=topi.first;
            if (node == query[1]) {
                ans.push_back(wt);found = true;
                break;
            }
            
            vis.insert(node);
            for(auto it:adj[node]){
                if (!vis.count(it.first)){
                    vis.insert(it.first);
                    q.push({it.first, wt * it.second});
                }
            }
        }

        if (!found)
                ans.push_back(-1.0);
        }
        return ans;
    }
};