class Solution {
public:
vector<pair<int,int>> directions{{-1,0},{1,0},{0,1},{0,-1}};

bool check(vector<vector<int>> distNearestThief, int sf,int n){
    queue<pair<int,int>> q;vector<vector<bool>> visited(n,vector<bool>(n,false));
    //00 to n-1n-1
    q.push({0,0});if(distNearestThief[0][0] < sf) return false;
    visited[0][0]=true;
    while(!q.empty()){
        int curr_i=q.front().first;
        int curr_j=q.front().second;
                q.pop();
                if(curr_i==n-1 && curr_j==n-1) return true;
                for(auto &it:directions){
                    int new_i=curr_i+it.first;
                    int new_j=curr_j+it.second;
                    if(new_i<0 || new_j<0 || new_i>=n || new_j>=n || visited[new_i][new_j]) continue;
                    if(distNearestThief[new_i][new_j]<sf) continue;
                    q.push({new_i,new_j});
                    visited[new_i][new_j]=true;
                }
    }
    return false;
}

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        vector<vector<int>> distNearestThief(n,vector<int>(n,-1));
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int curr_i=q.front().first;
                int curr_j=q.front().second;
                q.pop();
                distNearestThief[curr_i][curr_j]=level;
                for(auto &it:directions){
                    int new_i=curr_i+it.first;
                    int new_j=curr_j+it.second;
                    if(new_i<0 || new_j<0 || new_i>=n || new_j>=n || visited[new_i][new_j]) continue;
                    q.push({new_i,new_j});
                    visited[new_i][new_j]=true;
                }
            }
            level++;
        }
        //Applying BS on SF
        int l=0, r=400;
        int result=0;
        while(l<=r){
            int mid_sf=l+(r-l)/2;
            if(check(distNearestThief,mid_sf,n)){
                result=mid_sf;
                l=mid_sf+1;
            }
            else r=mid_sf-1;
        }
        return result;
    }
};