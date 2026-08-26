class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int sum=0;
        int cnt=0,l=0,pzero=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            while(l<i && (sum>goal || nums[l]==0) ){
                if(nums[l]==0) pzero++;
                else pzero=0;
                
                sum-=nums[l];
                l++;
            }
            if(sum==goal){
                cnt+=1+pzero;
            }
        }
        return cnt;
    }
};