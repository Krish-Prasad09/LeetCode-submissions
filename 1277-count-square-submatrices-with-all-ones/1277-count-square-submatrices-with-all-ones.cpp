class Solution {
public:
    int f(int i, int j, vector<vector<int>>& arr,
          vector<vector<int>>& dp) {

        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(arr[i][j] == 0)
            return dp[i][j] = 0;

        return dp[i][j] = 1 + min({
            f(i-1, j, arr, dp),
            f(i, j-1, arr, dp),
            f(i-1, j-1, arr, dp)
        });
    }

    int countSquares(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans += f(i, j, arr, dp);
            }
        }

        return ans;
    }
};