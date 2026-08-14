class Solution {
public:
int f(int ind, vector<int>& coins, int amount, vector<vector<int>> &dp,int curr){
    if(ind==0){
        if(curr%coins[ind] ==0)  return curr / coins[0];;
        return 10000000;
    }
    if(curr==0) return 0;
    if(curr < 0) return 10000000;
    if(dp[ind][curr]!=-1) return dp[ind][curr];
    int nottake=f(ind-1,coins,amount,dp,curr);
    int take=10000000;
    if(coins[ind]<=curr) take=1+f(ind,coins,amount,dp,curr-coins[ind]);
    return dp[ind][curr]=min(take,nottake);
}
//     int coinChange(vector<int>& coins, int amount) {
//         sort(coins.begin(),coins.end());
//         vector<int> coinss;
//         for(int i=0; i<coins.size(); i++){
//             int am=amount/coins[i];
//             while(am>0){
//                 coinss.push_back(coins[i]);
//                 am--;
//             }
//         }
//         vector<vector<int>> dp(
//     coinss.size(),
//     vector<int>(amount+1,-1)
// );
//         int curr=amount;
//         int ans= f(coinss.size()-1,coinss,amount,dp,curr);
//         return (ans >= 10000000 ? -1 : ans);
//     }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(
    coins.size(),
    vector<int>(amount+1,-1)
);
        int curr=amount;
        int ans= f(coins.size()-1,coins,amount,dp,curr);
        return (ans >= 10000000 ? -1 : ans);
    }
};