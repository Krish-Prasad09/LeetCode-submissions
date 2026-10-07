class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        int l = 0;
        long long cost = 0;
        int maxi = 0;
        if(n==1) return 1;

        for(int i = 1; i < n; i++) {

            cost += 1LL * (arr[i] - arr[i-1]) * (i-l);

            while(cost > k) {
                cost -= arr[i] - arr[l];
                l++;
            }

            maxi = max(maxi, i-l+1);
        }

        return maxi;
    }
};