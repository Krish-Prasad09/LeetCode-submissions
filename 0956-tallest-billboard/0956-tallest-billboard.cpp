class Solution {
public:
    int dp[21][10005];

    // Returns maximum possible height of the smaller pillar
    int solve(vector<int>& rods, int idx, int diff) {

        // Base case
        if (idx == rods.size()) {
            if (diff == 0)
                return 0;
            return INT_MIN;
        }

        // Already computed
        if (dp[idx][diff] != -1)
            return dp[idx][diff];

        // Put current rod on taller pillar
        int left = solve(rods, idx + 1, diff + rods[idx]);

        // Put current rod on shorter pillar
        int right = solve(rods, idx + 1, abs(diff - rods[idx]));

        if (right != INT_MIN)
            right += min(diff, rods[idx]);

        // Skip current rod
        int skip = solve(rods, idx + 1, diff);

        return dp[idx][diff] = max({left, right, skip});
    }

    int tallestBillboard(vector<int>& rods) {

        memset(dp, -1, sizeof(dp));

        return solve(rods, 0, 0);
    }
};