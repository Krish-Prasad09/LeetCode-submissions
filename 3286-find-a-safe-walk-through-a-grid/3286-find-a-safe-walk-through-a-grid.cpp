class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row = grid.size(), col = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        if (grid[0][0] == 1)
            health--;
        if (health <= 0)
            return false; // 1. MANDATORY: Track max health per cell to stop the
                          // infinite loops causing your MLE
        vector<vector<int>> maxh(row, vector<int>(col, -1));
        q.push({health, {0, 0}});
        maxh[0][0] = health;
        while (!q.empty()) {
            int h = q.front().first;
            int ri = q.front().second.first;
            int ci = q.front().second.second;
            int delr[] = {-1, 0, 1, 0};
            int delc[] = {0, 1, 0, -1};
            q.pop();
            if (ri == row - 1 && ci == col - 1 && h >= 1)
                return true;
            for (int i = 0; i < 4; i++) {
                int newr = delr[i] + ri;
                int newc = delc[i] + ci;
                if (newr < row && newr >= 0 && newc < col && newc >= 0) {
                    int next_h = h - grid[newr][newc];

                    if (next_h > maxh[newr][newc] && next_h > 0) {
                        maxh[newr][newc] = next_h;
                        q.push({next_h, {newr, newc}});
                    }
                }
            }
        }
        return false;
    }
};