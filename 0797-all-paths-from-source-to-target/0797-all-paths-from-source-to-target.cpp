class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> ans;
        queue<pair<int, vector<int>>> q;
        q.push({0,{0}});
        while(!q.empty()){
            auto [node,curr]=q.front();
            q.pop();
            if(node==n-1){
                ans.push_back(curr);
                continue;
            }
            for(auto &it:graph[node]){
                
                vector<int> next = curr;
                next.push_back(it);
                q.push({it, next});
            }
        }
        return ans;
    }
};