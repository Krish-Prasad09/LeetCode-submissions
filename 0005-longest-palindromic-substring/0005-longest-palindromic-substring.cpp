class Solution {
public:
    int maxl = 0, maxr = 0;

    vector<vector<int>> pal;
    vector<vector<bool>> vis;

    bool checkP(string &s, int l, int r) {

        if(l >= r)
            return true;

        if(pal[l][r] != -1)
            return pal[l][r];

        if(s[l] != s[r])
            return pal[l][r] = false;

        return pal[l][r] = checkP(s, l + 1, r - 1);
    }

    void solve(int l, int r, string &s) {

        if(l > r)
            return;

        if(vis[l][r])
            return;

        vis[l][r] = true;

        if(checkP(s, l, r)) {

            if(r - l + 1 > maxr - maxl + 1) {
                maxl = l;
                maxr = r;
            }
        }

        solve(l + 1, r, s);
        solve(l, r - 1, s);
    }

    string longestPalindrome(string s) {

        int n = s.length();

        pal.assign(n, vector<int>(n, -1));
        vis.assign(n, vector<bool>(n, false));

        solve(0, n - 1, s);

        return s.substr(maxl, maxr - maxl + 1);
    }
};