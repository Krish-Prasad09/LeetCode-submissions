class Solution {
public:
    int solve(int i, vector<int>& arr, int d, vector<int>& dp) {

        if(dp[i] != -1)
            return dp[i];

        int ans = 1;  // We can always stay at i

        // Go left
        for(int j = i-1; j >= max(0, i-d); j--) {

            if(arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + solve(j, arr, d, dp));
        }

        // Go right
        for(int j = i+1; j <= min((int)arr.size()-1, i+d); j++) {

            if(arr[j] >= arr[i])
                break;

            ans = max(ans, 1 + solve(j, arr, d, dp));
        }

        return dp[i] = ans;
    }


    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        vector<int> dp(n, -1);

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans = max(ans, solve(i, arr, d, dp));
        }

        return ans;
    }
};