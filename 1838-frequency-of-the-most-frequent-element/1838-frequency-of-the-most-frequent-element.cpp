class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int maxi=0;
        int cnt=0;
        int orik=k;
        long long current_window_sum = 0;
        for(int i=0; i<n; i++){
            current_window_sum += nums[i];
            cnt++;
            // IF: Agar saare elements ko nums[i] banane ka cost budget 'k' ke andar hai
            if ((long long)cnt * nums[i] - current_window_sum <= k) {
                maxi = max(maxi, cnt);
            }
            // ELSE: Agar budget se baahar gaya, toh bina loop ke left se ek element hatao
            else {
                current_window_sum -= nums[l];
                l++;
                cnt--; // Window choti hui toh count ek kam kar do
            }
        }
        return maxi;
    }
};