class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int curr = nums[0];
        int maxi = nums[0];
        int mini=nums[0];int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int curr1=maxi*nums[i];
            int curr2=mini*nums[i];
            maxi = max({nums[i],curr1,curr2});
            mini = min({nums[i],curr1,curr2});
            ans = max(ans, maxi);
        }
        
        return ans;
    }
};