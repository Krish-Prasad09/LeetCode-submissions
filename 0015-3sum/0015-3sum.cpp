class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            vector<int> curr(3,INT_MAX);
            int p=i+1,q=n-1;
            while(p<q){
                if(nums[i]+nums[p]+nums[q] <0){
                    p++;
                }
                else if(nums[i]+nums[p]+nums[q] >0){
                    q--;
                }
                else{
                    curr={nums[i],nums[p],nums[q]};
                    ans.push_back(curr);
                    p++;
                    q--;
                    while (p < q && nums[p] == nums[p-1]) p++;
                    while (p < q && nums[q] == nums[q+1]) q--;
                }
            }
        }
        return ans;
    }
};