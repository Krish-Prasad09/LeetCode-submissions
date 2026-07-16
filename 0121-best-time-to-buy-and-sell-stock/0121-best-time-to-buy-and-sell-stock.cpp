class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int sell=0,buy=INT_MAX;
        int maxi=0;
        for(int i=0; i<n; i++){
            buy=min(buy,prices[i]);
            sell=prices[i];
            maxi=max(maxi,sell-buy);
        }
        return maxi;
    }
};