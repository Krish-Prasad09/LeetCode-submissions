class Solution {
public:
set<vector<int>> ans;

    void solve(int ind, vector<int>& nums, vector<int> curr) {
        if(ind == nums.size()) {
            sort(curr.begin(),curr.end());
            ans.insert(curr);
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
        vector<vector<int>> res(ans.begin(),ans.end());
        sort(res.begin(),res.end());
        return res;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        return subsets(nums);
    }
};