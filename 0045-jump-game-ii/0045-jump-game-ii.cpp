class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumps=0;
        int l=0, r=0;
        for(int i=0; i<n-1; i++){
            r=max(r,i+nums[i]); //special line
            if(l==i){
                jumps++;
                l=r;
            }
        }
        return jumps;
    }
};