class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((nums[j] & 1) == 1) {
                    mp[i]++;
                }
                nums[j] >>= 1;
            }
        }
        long long ans = 0;
        long long MOD = 1e9 + 7;

        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int b = 0; b < 32; b++) {
                if (mp[b] > 0) {
                    x |= (1LL << b);
                    mp[b]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};