class Solution {
public:
int K=0;
bool isPalindrome(int l, int r, string &s){
        while(l < r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    int f(int i, int n, string &str, vector<int>& dp){
        if(i == n) return 0;

        if(dp[i] != -1)
            return dp[i];

        int minCost = f(i + 1, n, str, dp);;

        for (int j = i + K - 1; j <= min(i + K, n - 1); j++){
            if(j-i+1>=K && isPalindrome(i, j, str)){
                minCost = max(minCost, 1 + f(j + 1, n, str, dp));
            }
        }

        return dp[i] = minCost;
    }

    int minCut(string s) {
        int n = s.size();

        vector<int> dp(n, -1);

        return f(0, n, s, dp) - 1;
    }
    int maxPalindromes(string s, int k) {
        int n=s.length();
        K=k;
        return minCut(s)+1;
    }
};
