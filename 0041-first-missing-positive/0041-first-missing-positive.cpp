class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=1;
        for(int i=0; i<n; i++){
            if(nums[i]<=0 || (i>0 && nums[i]==nums[i-1])) continue;
            if(nums[i]==cnt){
                cnt++;
                continue;
            }
            else return cnt;
        }
        return (nums.back()+1)>0?nums.back()+1:1;
    }
};