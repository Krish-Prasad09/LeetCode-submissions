#define Mod 1000000007
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.length();
        vector<long long> sum(n,0);
        vector<long long> cnt(n,0);
        vector<long long> x(n,0);

        // powers of 10 modulo Mod
        vector<long long> p10(n + 1);
        p10[0] = 1;
        for (int i = 1; i <= n; i++)
            p10[i] = (p10[i - 1] * 10) % Mod;
        sum[0] = s[0] - '0';
        cnt[0] = (s[0] != '0');

        if (s[0] != '0')
            x[0] = s[0] - '0';

        for (int i = 1; i < n; i++) {
            int d = s[i] - '0';

            sum[i] = sum[i - 1] + d;
            cnt[i] = cnt[i - 1] + (d > 0);

            if (d > 0)
                x[i] = (x[i - 1] * 10 + d) % Mod;
            else
                x[i] = x[i - 1];
        }
        int m=queries.size();
        vector<int> res(m);
        for(int i=0; i<m; i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int len = cnt[r] - (l ? cnt[l - 1] : 0);

            long long currX;
            if(l > 0)
                currX = (x[r] - x[l - 1] * p10[len] % Mod + Mod) % Mod;
            else
                currX = x[r] % Mod;
            long long curSum = (sum[r] - (l ? sum[l - 1] : 0) + Mod) % Mod;
            res[i]=(currX*curSum)%Mod;
        }
        return res;
    }
};