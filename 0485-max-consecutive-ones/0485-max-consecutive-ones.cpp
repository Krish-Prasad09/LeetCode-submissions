class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int sum=0,maxi=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                sum=0;
                continue;
            }
            sum+=1;
            maxi=max(maxi,sum);
            
        }
        return maxi;
    }
};