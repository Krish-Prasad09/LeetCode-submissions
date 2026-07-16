class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int beg=0;
        vector<vector<int>> res;
        for(int i=0; i<n; i++){
            vector<int> curr(2);
            beg=intervals[i][0];
            int end=intervals[i][1];
            int cnt=1;
            while(true && i+cnt<n){
                int newbeg=intervals[i+cnt][0];
                if(newbeg<=end){
                    end=max(end,intervals[i+cnt][1]);
                    cnt++;
                }
                else{
                    break;
                }
            }
            curr = {beg, end};
            res.push_back(curr);
            i=i+cnt-1;
        }
        return res;
    }
};