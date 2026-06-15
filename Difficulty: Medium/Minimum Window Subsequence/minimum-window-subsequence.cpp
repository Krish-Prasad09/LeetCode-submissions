class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string &s1, string &s2, int n1, int n2) {
        if(j == n2)
            return i - 1;

        if(i == n1)
            return 1e9;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = solve(i + 1, j + 1, s1, s2, n1, n2);

        return dp[i][j] = solve(i + 1, j, s1, s2, n1, n2);
    }

    string minWindow(string &s1, string &s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        dp.assign(n1 + 1, vector<int>(n2 + 1, -1));

        int bestLen = 1e9;
        string ans = "";

        for(int start = 0; start < n1; start++) {
            if(s1[start] == s2[0]) {
                int end = solve(start, 0, s1, s2, n1, n2);

                if(end != 1e9) {
                    int len = end - start + 1;

                    if(len < bestLen) {
                        bestLen = len;
                        ans = s1.substr(start, len);
                    }
                }
            }
        }

        return ans;
    }
};