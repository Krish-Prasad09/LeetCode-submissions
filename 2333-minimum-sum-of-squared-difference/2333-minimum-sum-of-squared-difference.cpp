class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        
        // Frequencies of each difference (max difference is 100,000)
        vector<long long> count(100001, 0); 
        int maxDiff = 0;
        
        for(int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            count[diff]++;
            maxDiff = max(maxDiff, diff); // Track the highest difference to save time
        }
        
        // Start from the highest difference and reduce in bulk
        for (int i = maxDiff; i > 0 && k > 0; i--) {
            if (count[i] > 0) {
                // If we have 'k' operations left, we can at most reduce 'k' elements.
                // Otherwise, we reduce all elements that currently have this difference.
                long long deduct = min(count[i], k);
                
                count[i] -= deduct;       // These elements are no longer difference 'i'
                count[i - 1] += deduct;   // They are now difference 'i - 1'
                k -= deduct;              // Subtract operations used
            }
        }
        
        // Calculate the final sum of squares
        long long sum = 0;
        for (long long i = 1; i <= maxDiff; i++) {
            if (count[i] > 0) {
                sum += i * i * count[i];
            }
        }
        
        return sum;
    }
};