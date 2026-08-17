class Solution {
public:
vector<vector<int>> dp;
int f(int l, int r, vector<int> &arr,vector<int> &prefS){
    if(l==r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int sumo = accumulate(arr.begin() + l, arr.begin() + r + 1, 0);
    
    int alice=0;
    for(int k=l; k<r; k++){
        int sum1=0;
        int alice1=0,alice2=0,alice3=0;
        // for(int i=l; i<=k; i++){
        //     sum1+=arr[i];
        // }
        if(l == 0)
            sum1 = prefS[k];
        else
            sum1 = prefS[k] - prefS[l-1];
        int sum2=sumo-sum1;
        if(sum1>sum2){
             alice1=sum2+f(k+1,r,arr,prefS);
        }
        else if(sum1<sum2){
             alice2=sum1+f(l,k,arr,prefS);
        }
        else{
             alice3=sum1+max(f(l,k,arr,prefS),f(k+1,r,arr,prefS));
        }
        alice=max({alice,alice1,alice2,alice3});
    }
    return dp[l][r]=alice;
}
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> prefS(n,0);
        for(int i=0; i<n; i++){
            if(i!=0)prefS[i]=prefS[i-1]+stoneValue[i];
            else prefS[i]=stoneValue[i];
        }
        dp.assign(n+1,vector<int>(n+1,-1));
        return f(0,n-1,stoneValue,prefS);
    }
};