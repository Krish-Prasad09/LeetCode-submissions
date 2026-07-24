class Solution { //CONVEX HULL
public:
    // Cross product
    // > 0 : clockwise turn
    // < 0 : counter-clockwise turn
    // = 0 : collinear
    int cross(vector<int> &a, vector<int> &b, vector<int> &c) {
        return (c[1] - b[1]) * (b[0] - a[0]) -
               (b[1] - a[1]) * (c[0] - b[0]);
    } //(c.y-b.y)*(b.x-a.x) - (b.y-a.y)*(c.x-b.x)

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {

        // Sort according to x, then y
        sort(trees.begin(), trees.end());

        vector<vector<int>> lower, upper;

        for (auto &point : trees) {

            // Build lower hull
            // Remove previous point if we make a clockwise turn
            while (lower.size() >= 2 &&
                   cross(lower[lower.size()-2], lower.back(), point) > 0)
                lower.pop_back();

            lower.push_back(point);

            // Build upper hull
            // Remove previous point if we make a counter-clockwise turn
            while (upper.size() >= 2 &&
                   cross(upper[upper.size()-2], upper.back(), point) < 0)
                upper.pop_back();

            upper.push_back(point);
        }

        // Merge both hulls
        set<vector<int>> ans;

        for (auto &p : lower)
            ans.insert(p);

        for (auto &p : upper)
            ans.insert(p);

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};