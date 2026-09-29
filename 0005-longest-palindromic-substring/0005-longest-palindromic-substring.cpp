class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxl = 0;
        int maxlen = 1;

        // Length 1
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Length 2 to n
        for(int len = 2; len <= n; len++) {

            for(int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                if(s[l] == s[r]) {

                    if(len == 2)
                        dp[l][r] = true;
                    else
                        dp[l][r] = dp[l+1][r-1];
                }

                if(dp[l][r] && len > maxlen) {
                    maxlen = len;
                    maxl = l;
                }
            }
        }

        return s.substr(maxl, maxlen);
    }
};