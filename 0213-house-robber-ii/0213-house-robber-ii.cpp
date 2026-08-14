class Solution {
public:
    int f(int ind, int last, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();

        if(ind >= n) return 0;

        if(dp[ind][last + 1] != -1)
            return dp[ind][last + 1];

        int nottake = f(ind + 1, last, nums, dp);

        int take = 0;

        if(ind == 0)
            last = 1;

        if(!(last == 1 && ind == n - 1))
            take = nums[ind] + f(ind + 2, last, nums, dp);

        return dp[ind][last + 1] = max(take, nottake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<vector<int>> dp(n, vector<int>(3, -1));

        return f(0, -1, nums, dp);
    }
};