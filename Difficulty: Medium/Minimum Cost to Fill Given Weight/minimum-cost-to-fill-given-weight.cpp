class Solution {
  public:
  int f(int ind, int n, int w, vector<int>& cost,vector<vector<int>> &dp){
      if(w<0) return INT_MAX;
      if(w==0) return 0;
      if(ind>=n) return INT_MAX;
      if(dp[ind][w]!=-1) return dp[ind][w];
      
      int nottake=f(ind+1, n, w, cost, dp);
      if(cost[ind]==-1) return nottake;
      int take=INT_MAX;
      int sub = f(ind, n, w-(ind+1), cost, dp);
    if(sub != INT_MAX)
    take = cost[ind] + sub;
    //   if(w-(ind+1) >=0) take=cost[ind] +f(ind,n,w-(ind+1),cost);
      return dp[ind][w]=min(take,nottake);
  }
    int minimumCost(vector<int> &cost, int w) {
        // code here
        int n=cost.size();
        vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
        int ans= f(0,n,w,cost,dp);
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};
