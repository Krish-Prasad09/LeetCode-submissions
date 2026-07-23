class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        set<int> st;
        if (n == 1) return 1;
        if (n == 2) return 2;

        // For n >= 3, find the smallest power of 2 strictly greater than n
        int powerOfTwo = 1;
        while (powerOfTwo <= n) {
            powerOfTwo <<= 1;
        }
        
        return powerOfTwo;
    }
};