class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        std::next_permutation(nums.begin(),nums.end());
    }
};