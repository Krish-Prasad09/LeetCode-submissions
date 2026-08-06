class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row=maze.size();
        int col=maze[0].size();
        int sr=entrance[0], sc=entrance[1];
        queue<vector<int>> q; //r,c,steps
        q.push({sr,sc,0});maze[sr][sc] = '+';
        while(!q.empty()){
            auto topi=q.front();
            q.pop();
            int r=topi[0];
            int c=topi[1];
            int steps=topi[2];
           if ((r == 0 || c == 0 || r == row - 1 || c == col - 1) &&
            !(r == sr && c == sc))
            return steps;
            int delr[]={-1,0,1,0};
            int delc[]={0,1,0,-1};
            for(int i=0; i<4; i++){
                int newr=delr[i]+r;
                int newc=c+delc[i];
                if(newc<0 || newr<0 || newr>=row || newc>=col || maze[newr][newc]=='+') continue;
                maze[newr][newc]='+';
                q.push({newr,newc,steps+1});
            }
        }
        return -1;
    }
};