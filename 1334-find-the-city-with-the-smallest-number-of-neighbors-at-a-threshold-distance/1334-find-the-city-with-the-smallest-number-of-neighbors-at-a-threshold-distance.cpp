class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int cnt=0;
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++) {
            matrix[i][i] = 0;
        }
        for(auto it:edges){
            int r=it[0], c=it[1];
            matrix[r][c] = it[2];
            matrix[c][r] = it[2];
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(j!=i)matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        int mini=INT_MAX;
        int ans=0;
        for(int i = 0; i < n; i++) {

            cnt = 0;

            for(int j = 0; j < n; j++) {

                if(i != j && matrix[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }

            if(cnt <= mini) {
                mini = cnt;
                ans = i;
            }
        }
        return ans;
    }
};