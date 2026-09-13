class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<vector<int>> shifts(2 * n, vector<int>(2 * n, 0));
        int maxOverlap = 0;
        for (int r1 = 0; r1 < n; r1++) {
            for (int c1 = 0; c1 < n; c1++) {
                if (img1[r1][c1] != 1) continue;
                for (int r2 = 0; r2 < n; r2++) {
                    for (int c2 = 0; c2 < n; c2++) {
                        if (img2[r2][c2] != 1) continue;
                        int rowShift = n + r1 - r2;
                        int colShift = n + c1 - c2;
                        shifts[rowShift][colShift]++;
                        maxOverlap = max(
                            maxOverlap,
                            shifts[rowShift][colShift]
                        );
                    }
                }
            }
        }
        return maxOverlap;
    }
};