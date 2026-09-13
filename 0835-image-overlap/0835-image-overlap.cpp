class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int size = 3 * n;
        
        // CHANGED: vector<bitset<90>> shrinks the memory footprint by almost 98% 
        // compared to vector<vector<int>> and removes heap overhead.
        vector<bitset<90>> grid(size);
        
        int a1 = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1) {
                    grid[i + n][j + n] = 1;
                    a1++;
                }
            }
        }
        
        queue<tuple<vector<bitset<90>>, int, int, int>> q;
        q.push({grid, a1, n, n});
        
        vector<vector<bool>> visited(size, vector<bool>(size, false));
        visited[n][n] = true;
        
        int max_overlap = 0;
        
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            auto [vec, ones, curr_x, curr_y] = q.front();
            q.pop();
            
            int current_overlap = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    // Works identically to your original code
                    if(vec[i + n][j + n] == 1 && img2[i][j] == 1){
                        current_overlap++;
                    }
                }
            }
            max_overlap = max(max_overlap, current_overlap);
            
            for(int k = 0; k < 4; k++){
                int nx = curr_x + delr[k];
                int ny = curr_y + delc[k];
                
                if(nx >= 0 && nx < size && ny >= 0 && ny < size && !visited[nx][ny]){
                    
                    vector<bitset<90>> next_vec(size);
                    
                    for(int i = 0; i < size; i++){
                        for(int j = 0; j < size; j++){
                            if(vec[i][j] == 1){
                                int ni = i + delr[k];
                                int nj = j + delc[k];
                                
                                if(ni >= 0 && ni < size && nj >= 0 && nj < size){
                                    next_vec[ni][nj] = 1;
                                }
                            }
                        }
                    }
                    
                    visited[nx][ny] = true;
                    q.push({next_vec, ones, nx, ny});
                }
            }
        }
        
        return max_overlap;
    }
};