class Solution {
public:
vector<vector<int>> dp;
int solve(int i, int cnt, vector<vector<int>>& events) {
        int n = events.size();

        // Taken 2 events already OR no events left
        if (i >= n || cnt == 2)
            return 0;

        if (dp[i][cnt] != -1)
            return dp[i][cnt];

        // Don't take current event
        int nottake = solve(i + 1, cnt, events);

        // Take current event
        int next = n;

        // Find first event with start > current end
        int l = i + 1, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (events[mid][0] > events[i][1]) {
                next = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        int take = events[i][2] + solve(next, cnt + 1, events);

        return dp[i][cnt] = max(take, nottake);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        dp.assign(n, vector<int>(2, -1));
        return solve(0, 0, events);
    }
};