class Solution {
public:
    string longestPrefix(string s) {
        long long prefix = 0;
        long long suffix = 0;
        long long base = 29;
        long long power = 1;
        long long mod = 1e9 + 7;

        int len = 0;
        int n=s.length();

        for (int i = 0; i < s.size()-1; i++) {

            long long ch = s[i] - 'a' + 1;

            prefix = (prefix * base + ch) % mod;

            // suffix = (suffix + ch * power) % mod;
            suffix = (suffix + (s[n-1-i]-'a'+1) * power) % mod;
            power = (power * base) % mod;

            if (prefix == suffix) 
                len =i+1;
        }

        return s.substr(0,len);
    }
};