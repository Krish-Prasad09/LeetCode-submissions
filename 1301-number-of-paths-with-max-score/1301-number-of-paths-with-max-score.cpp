class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<pair<int,int>>> dp;

    pair<int,int> f1(int indr, int indc, vector<string>& board, int row, int col){

        if(indr < 0 || indr >= row || indc < 0 || indc >= col || board[indr][indc]=='X'){
            return {INT_MIN, 0};
        }

        if(indr==0 && indc==0) return {0,1};

        if(dp[indr][indc].first != -2)
            return dp[indr][indc];

        int delr[]={-1,0,-1};
        int delc[]={0,-1,-1};

        int maxi=INT_MIN;
        int ways=0;

        for(int i=0; i<3; i++){
            int newr=delr[i]+indr;
            int newc=delc[i]+indc;

            auto res = f1(newr, newc, board, row, col);

            if(res.first != INT_MIN){
                int current_val = (board[newr][newc] == 'E') ? 0 : (board[newr][newc] - '0');
                int score = current_val + res.first;

                if(score > maxi){
                    ways = res.second;
                }
                else if(score == maxi){
                    ways = (ways + res.second) % MOD;
                }

                maxi = max(maxi, score);
            }
        }

        return dp[indr][indc] = {maxi, ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int row = board.size();
        int col = board[0].size();

        dp.assign(row, vector<pair<int,int>>(col, {-2,-1}));

        auto ans = f1(row-1, col-1, board, row, col);

        if(ans.first == INT_MIN)
            return {0,0};

        return {ans.first, ans.second};
    }
};