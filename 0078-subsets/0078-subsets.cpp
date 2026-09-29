class Solution {
public:
    vector<vector<int>> ans;

    void solve(int ind, vector<int>& nums, vector<int> curr) {
        if(ind == nums.size()) {
            ans.push_back(curr);
            return;
        }

         // Not take
        solve(ind + 1, nums, curr);

        // Take
        curr.push_back(nums[ind]);
        solve(ind + 1, nums, curr);

       
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        solve(0, nums, curr);
        return ans;
    }
};