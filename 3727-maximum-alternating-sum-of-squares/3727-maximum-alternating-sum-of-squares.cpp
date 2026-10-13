class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1,arr2;
        for(int i=0; i<n; i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.rbegin(),nums.rend());
        if(n%2 ==0){
            long long sum1=0,sum2=0;
            for(int i=0; i<n;i++){
                if(i<n/2){
                    sum1+=nums[i]*nums[i];
                }
                else sum2+=nums[i]*nums[i];
            }return sum1-sum2;
        }
        else{
            long long sum1=0,sum2=0;
            for(int i=0; i<n;i++){
                if(i<=n/2){
                    sum1+=nums[i]*nums[i];
                }
                else sum2+=nums[i]*nums[i];
            }
            return sum1-sum2;
        }
        return -1;
    }
};