class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int row=numRows;
        vector<vector<int>> ans;
        for(int i=0; i<row; i++){
            vector<int> curr;
            for(int j=0; j<i+1; j++){
                if(i==0 || j==0 || j==i) curr.push_back(1);
                else curr.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};