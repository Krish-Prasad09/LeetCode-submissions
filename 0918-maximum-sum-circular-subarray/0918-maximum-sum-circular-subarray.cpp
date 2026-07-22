class Solution {
public:
int minSubArray(vector<int>& nums) {
        int curr = nums[0];
        int mini = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            curr = min(nums[i], curr + nums[i]);
            mini = min(mini, curr);
        }

        return mini;
    }
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int maxi = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            curr = max(nums[i], curr + nums[i]);
            maxi = max(maxi, curr);
        }

        return maxi;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxu=maxSubArray(nums);
        if(maxu<0) return maxu;
        return max(accumulate(nums.begin(),nums.end(),0) -minSubArray(nums),maxu);
    }
};