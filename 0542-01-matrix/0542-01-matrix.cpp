class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> vis(row, vector<int>(col, 0));
        queue<pair<pair<int,int>, int>> q;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {

                if(mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            int r = node.first.first;
            int c = node.first.second;
            int d = node.second;

            for(int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < row &&
                   nc >= 0 && nc < col &&
                   vis[nr][nc] == 0) {

                    vis[nr][nc] = 1;
                    mat[nr][nc] = d + 1;

                    q.push({{nr, nc}, d + 1});
                }
            }
        }

        return mat;
    }
};