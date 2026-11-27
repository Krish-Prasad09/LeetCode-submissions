// class Solution {
// public:int ans=0,minPrice=INT_MAX;
//     int dp[1001][1501];
//     vector<int> freeOf;
//     void recurser(vector<int>& price,int budget,int ind,int cost, int purchased){
//         if (ind == (int)price.size()) {
//             int total = purchased + (budget - cost) / minPrice;
//             ans = max(ans, total);
//             return;
//         }
//         if (dp[ind][cost] >= purchased  ) return;
//         dp[ind][cost] = purchased ;
//         recurser(price, budget, ind + 1, cost, purchased);

//         if (cost + price[ind] <= budget) {
//             recurser(price, budget, ind + 1,
//                      cost + price[ind],
//                      purchased + 1 + freeOf[ind]);  // baked in
//         }
//     }
//     int maximumSaleItems(vector<vector<int>>& items, int budget) {
//         int row=items.size();
//         vector<int> factor(row,0);
//         vector<int> price(row,0);
//         freeOf.resize(row, 0);
//         for (int i = 0; i < row; i++)
//             for (int j = 0; j < row; j++)
//                 if (j != i && items[j][0] % items[i][0] == 0)
//                     freeOf[i]++;
//         for(int i=0; i<row; i++){
//             factor[i]=items[i][0];
//             price[i]=items[i][1];
//             minPrice=min(minPrice,price[i]);
//         }
//         memset(dp, -1, sizeof(dp));
//         recurser(price, budget, 0, 0, 0);
//         return ans;
//     }
// };

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        
        int minPrice = INT_MAX;
        vector<int> freeOf(n, 0);
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (j != i && items[j][0] % items[i][0] == 0)
                    freeOf[i]++;
        
        for (int i = 0; i < n; i++)
            minPrice = min(minPrice, items[i][1]);
        
        vector<int> dp(budget + 1, -1);
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            int p = items[i][1];
            for (int c = budget; c >= p; c--) {
                if (dp[c - p] == -1) continue;
                dp[c] = max(dp[c], dp[c - p] + 1 + freeOf[i]);
            }
        }
        
        int ans = 0;
        for (int c = 0; c <= budget; c++) {
            if (dp[c] == -1) continue;
            ans = max(ans, dp[c] + (budget - c) / minPrice);
        }
        
        return ans;
    }
};