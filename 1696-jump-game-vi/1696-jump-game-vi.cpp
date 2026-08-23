class Solution {
public:
    int maxResult(vector<int>& arr, int k) {

        int n = arr.size();

        vector<int> dp(n);

        deque<int> dq;

        dp[0] = arr[0];
        dq.push_back(0);

        for(int i = 1; i < n; i++) {

            // Remove indices outside the range [i-k, i-1]
            while(!dq.empty() && dq.front() < i-k)
                dq.pop_front();

            // Maximum dp in the last k positions
            dp[i] = arr[i] + dp[dq.front()];

            // Remove smaller dp values
            while(!dq.empty() && dp[dq.back()] <= dp[i])
                dq.pop_back();

            dq.push_back(i);
        }

        return dp[n-1];
    }
};