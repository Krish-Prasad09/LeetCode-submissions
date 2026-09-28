class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int pres=INT_MIN,pree=INT_MIN,cnt=0;
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            int s=intervals[i][0];
            int e=intervals[i][1];

            if(s>pree){
                pres=s;
                pree=e;
                ans.push_back({s,e});
            }
            else {
                pree=max(pree,e);
                ans.back()[1]=pree;
            }
        }
        return ans;
    }
};