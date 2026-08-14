class Solution {
public:
    int f(int ind, int target, vector<int>& nums,
          vector<vector<int>>& dp) {

        if(target == 0)
            return 1;

        if(ind == 0)
            return nums[0] == target;

        if(dp[ind][target] != -1)
            return dp[ind][target];

        int nottake = f(ind - 1, target, nums, dp);

        int take = 0;

        if(nums[ind] <= target)
            take = f(ind - 1, target - nums[ind], nums, dp);

        return dp[ind][target] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;

        for(auto it : nums)
            total += it;

        if(total % 2 != 0)
            return false;

        int target = total / 2;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(target + 1, -1)
        );

        return f(nums.size() - 1, target, nums, dp);
    }
};