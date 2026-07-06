class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int cnt=0, n=intervals.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j==i) continue;
                int a=intervals[i][0];
                int b=intervals[i][1];
                int c=intervals[j][0];
                int d=intervals[j][1];
                if(c<=a && b<=d){
                    cnt++;
                    break;
                }
            }
        }
        return n-cnt;
    }
};