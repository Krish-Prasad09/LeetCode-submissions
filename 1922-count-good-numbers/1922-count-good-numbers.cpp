const int mod=(1e9+7);
class Solution {
public:
long long power(long long a, long long b) {
    long long mod = 1e9 + 7;
    long long ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
    int countGoodNumbers(long long n) {
        if(n==1) return 5;
        if(n%2==0) return power(20,n/2)%mod;
        else return (power(20,(n-1)/2)*5)%mod;
    }
};