class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int m=*max_element(nums.begin(),nums.end());
        vector<long long> cnt(m+1,0);
        for (int num : nums) cnt[num]++;
        
        for(int i=1; i<=m; i++){
            for(int j=i*2; j<=m; j+=i){
                cnt[i]+=cnt[j];
            }
        } 
        //After this loop cnt[i] means Number of elements divisible by i
        for(int i=1; i<=m; i++){
            cnt[i]= cnt[i]*(cnt[i]-1)/2;
        }
        //After this, cnt[i] means Number of pairs whose GCD is a multiple of i


        //Example (6,12) has gcd 6 but it got counted in i=1,2,3,6
        //So we remove overcounting as we want pairs having gcd exactly i
        for (int i = m; i >= 1; i--) {
            for (int j = i * 2; j <= m; j += i) {
                cnt[i] -= cnt[j];
            }
        }

        //Prefix lets us know where each gcd starts and ends.Up to gcd 2 there are 7 pairs.
        for(int i=1; i<=m; i++){
            cnt[i]+=cnt[i-1];
        }
        vector<int> ans;
        //q=5 means 6th smallest gcd bcoz queries are 0-indexed, we need prefix>=6 
        for(long long q:queries){
            long long target=q+1;
            int pos=lower_bound(cnt.begin(),cnt.end(),target) -cnt.begin();
            ans.push_back(pos);
        }
        return ans;

    }
};