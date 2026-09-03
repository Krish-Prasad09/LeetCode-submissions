class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        pair<int, int> po = {-1, -1}; // {smallest_odd_value, index}
        vector<int> nums2o;

        // Pass 1: Find the SMALLEST odd element in the array
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 != 0) {
                if (po.first == -1 || nums1[i] < po.first) {
                    po = {nums1[i], i};
                }
            }
        }

        // If there are no odds, the array is already all-even -> true
        if (po.first == -1) return true;

        // Pass 2: Try to turn all numbers odd using the smallest odd element
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 != 0) {
                nums2o.push_back(nums1[i]);
            } else if (nums1[i] - po.first >= 1) {
                nums2o.push_back(nums1[i] - po.first);
            }
        }

        return nums2o.size() == n;
    }
};