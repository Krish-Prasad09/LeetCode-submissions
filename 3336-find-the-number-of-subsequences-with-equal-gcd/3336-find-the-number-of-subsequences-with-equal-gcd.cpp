#define mod 1000000007
class Solution {
public:
int memo[201][201][201];
int n=0;
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
int f(int i, int g1,int g2, vector<int> &nums){
    if(i>=n) return (g1 > 0 && g2 > 0 && g1 == g2) ? 1 : 0;
    if (memo[i][g1][g2] != -1) {
            return memo[i][g1][g2];
        }
    int nottake=f(i+1,g1,g2,nums) % mod;  //skip nums[i]
    int nextg1,nextg2;
    if(g1==0)  nextg1=nums[i];
    else  nextg1=gcd(g1,nums[i]);

    if(g2==0)  nextg2=nums[i];
    else  nextg2=gcd(g2,nums[i]);

    int take=(f(i + 1, g1, nextg2, nums) +f(i + 1, nextg1,g2, nums) ) % mod;

    return memo[i][g1][g2] =(take+nottake)%mod;
}
    int subsequencePairCount(vector<int>& nums) {
        n=nums.size();
        memset(memo, -1, sizeof(memo));
        return f(0,0,0,nums);
    }
};