class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++) {
            if(nums[i] % k == 0)
                pq.push(nums[i]);
        }

        for(int i = k; ; i += k) {
            if (pq.empty() || pq.top() > i) return i;
            while (!pq.empty() && pq.top() == i) pq.pop();
        }
    }
};