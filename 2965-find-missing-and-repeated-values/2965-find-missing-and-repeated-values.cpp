class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m=grid.size();
        long long n=m*m;
        long long sums=0,sumsq=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
            sums+=(grid[i][j]);
            sumsq+=1LL*(grid[i][j])*grid[i][j];
            }
        }
        long long ans1=sums- (n*(n+1))/2;
        long long ans2=sumsq- 1LL*(n*(n+1)*(2*n+1))/6;
        
        long long R=((ans2)/ans1 +ans1)/2;
        long long M=((ans2)/ans1 -ans1)/2;
        int rr=R;
        int mm=M;
        vector<int> ans;
        ans.push_back(rr);
        ans.push_back(mm);
        return ans;
        
    }
};