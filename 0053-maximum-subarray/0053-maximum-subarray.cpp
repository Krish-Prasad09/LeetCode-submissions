class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefSum=0;
        unordered_map<int,int> mp;
        int n=nums.size();
        if(n==1) return nums[0];
        int prev=0;
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            if(prefSum<prev) prev=prefSum;
            prefSum+=nums[i];
            maxi=max(maxi,prefSum-prev);
        }        
        return maxi;
    }
};