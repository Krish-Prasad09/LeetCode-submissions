class Solution {
public:
    vector<vector<int>> dp;

    bool helper(int ind, string &s, int cnt) {
        if (cnt < 0) return false;

        if (ind == s.length())
            return cnt == 0;

        if (dp[ind][cnt] != -1)
            return dp[ind][cnt];

        if (s[ind] == '(')
            return dp[ind][cnt] = helper(ind + 1, s, cnt + 1);

        if (s[ind] == ')')
            return dp[ind][cnt] = helper(ind + 1, s, cnt - 1);

        // s[ind] == '*'
        return dp[ind][cnt] =
            helper(ind + 1, s, cnt + 1) ||   // '* = '('
            helper(ind + 1, s, cnt - 1) ||   // '* = ')'
            helper(ind + 1, s, cnt);         // '* = empty'
    }

    bool checkValidString(string s) {
        int n = s.length();

        dp.assign(n, vector<int>(n + 1, -1));

        return helper(0, s, 0);
    }
};