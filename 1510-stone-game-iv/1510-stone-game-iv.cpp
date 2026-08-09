class Solution {
public:
bool check(int n) {     int x = sqrt(n);     return x * x == n; }
vector<vector<int>> dp;
bool f(int n, bool chance){

    if(n==0 && chance==0) return false;
    if(n==0 && chance==1) return true;
    if(dp[n][chance] != -1)
            return dp[n][chance];
    if(chance==0){
        for(int i=n; i>0; i--){
            if(check(i)){
                if(f(n-i,!chance))  return dp[n][chance] = true;
            }
        }
         return dp[n][chance] = false;
    }
    else{
        for(int i=n; i>0; i--){
            if(check(i)){
                if( !f(n-i,!chance))  return dp[n][chance] = false;
            }
        }
         return dp[n][chance] = true;
    }
}
    bool winnerSquareGame(int n) {
        dp.assign(n + 1, vector<int>(2, -1));
        return f(n, 0);
    }
};