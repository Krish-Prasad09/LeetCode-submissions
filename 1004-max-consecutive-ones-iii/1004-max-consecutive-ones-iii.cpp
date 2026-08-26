class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,maxi=INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                k--;
            }
            while(k<0){
                if(nums[l]==0){
                    k++;
                }
                l++;
            }
            maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};