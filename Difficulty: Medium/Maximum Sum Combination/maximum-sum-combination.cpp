class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        priority_queue<pair<int,pair<int,int>>> pq;
        int i=n-1,j=n-1;
        set<pair<int,int>> vis;
        pq.push({a[n-1] + b[n-1], {n-1, n-1}});vector<int> ans;
        vis.insert({n-1, n-1});
        while(k){
            auto curr = pq.top();
            pq.pop();
            int sum = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;
            ans.push_back(sum);

            if (i - 1 >= 0 && !vis.count({i-1, j})) {
                pq.push({a[i-1] + b[j], {i-1, j}});
                vis.insert({i-1, j});
            }

            if (j - 1 >= 0 && !vis.count({i, j-1})) {
                pq.push({a[i] + b[j-1], {i, j-1}});
                vis.insert({i, j-1});
            }
            k--;
        }
        return ans;
    }
};