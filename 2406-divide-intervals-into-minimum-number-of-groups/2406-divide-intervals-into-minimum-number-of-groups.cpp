class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int pres=-1,pree=-1;
        int n=intervals.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<n; i++){
            int s=intervals[i][0];
            int e=intervals[i][1];
            if(!pq.empty() && s > pq.top())
                pq.pop();

            pq.push(e);
        }
        return pq.size();
    }
};