class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int i=0;
        while(i<=maxi){
            if(i>=n-1) return true;
            maxi=max(maxi,i+nums[i]);
            if(maxi==i) return false;
            i++;
        }
        return i>=n-1;
    }
};