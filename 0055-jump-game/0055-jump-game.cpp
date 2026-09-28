class Solution {
public:
    vector<int> dp;

    bool solve(int i, vector<int>& nums) {
        if(i >= nums.size() - 1)
            return true;

        if(dp[i] != -1)
            return dp[i];

        for(int jump = 1; jump <= nums[i]; jump++) {
            if(solve(i + jump, nums))
                return dp[i] = true;
        }

        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);

        return solve(0, nums);
    }
};