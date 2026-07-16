class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        long long maxi=0;
        for(int i=0; i<n; i++){
            maxi=max((int)maxi,nums[i]);
            nums[i]=std::gcd(nums[i],maxi);
        }
        sort(nums.begin(),nums.end());
        long long sum=0;
        for(int i=0; i<n/2; i++){
            sum+=std::gcd(nums[i],nums[n-i-1]);
        }
        return sum;
    }
};