class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l = 0;
        int r = n - 1;

        int maxi = 0;

        while(l < r) {
            int width = r - l;
            int h = min(height[l], height[r]);

            maxi = max(maxi, width * h);

            if(height[l] < height[r])
                l++;
            else
                r--;
        }

        return maxi;
    }
};