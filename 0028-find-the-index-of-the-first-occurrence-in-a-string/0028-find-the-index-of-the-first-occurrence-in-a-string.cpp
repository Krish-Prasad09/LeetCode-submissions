class Solution {
public:vector<int> search(string pat, string txt) {
        vector<int> res;

        int n = txt.size();
        int m = pat.size();

        long long d = 256;      // character set size
        long long q = 1e9 + 7;  // large prime

        long long p = 0; // pattern hash
        long long t = 0; // text window hash
        long long h = 1;

        // h = d^(m-1) % q
        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        // initial hashes
        for (int i = 0; i < m; i++) {
            p = (d * p + pat[i]) % q;
            t = (d * t + txt[i]) % q;
        }

        for (int i = 0; i <= n - m; i++) {

            // hash matched
            if (p == t) {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (txt[i + j] != pat[j]) {
                        match = false;
                        break;
                    }
                }

                if (match)
                    res.push_back(i);   // i+1 for GFG
            }

            // rolling hash
            if (i < n - m) {
                t = (d * (t - txt[i] * h) + txt[i + m]) % q;

                if (t < 0)
                    t += q;
            }
        }

        return res;
    }
    int strStr(string haystack, string needle) {
        int n1=haystack.length(), n2=needle.length();
        vector<int>ans= search(needle,haystack);
        if(ans.size()==0) return -1;
        else return ans[0];
    }
};