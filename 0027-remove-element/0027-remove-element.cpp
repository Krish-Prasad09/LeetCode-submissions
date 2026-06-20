class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        vector<int>index;
        for(int i=0; i<n; i++){
            if(nums[i]==val){
                index.push_back(i);
            }
        }
        int value=0;
        for(int it=0; it<index.size();it++){
            nums.erase(nums.begin() + index[it] - value);
            value++;
        }
        return nums.size();
    }
};