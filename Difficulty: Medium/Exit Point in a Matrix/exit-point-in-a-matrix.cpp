class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        // code here
        int row=mat.size();
        int col=mat[0].size();
        queue<tuple<int,int,int>> q;
        vector<int> ans;
        q.push({0,0,5});
        while(!q.empty()){
            auto [r, c, wheres] = q.front();
            q.pop();
            if(r<0){
                ans.push_back(r+1);
                ans.push_back(c);
                break;
            }
            if(c<0){
                ans.push_back(r);
                ans.push_back(c+1);
                break;
            }
            if(r>row-1){
                ans.push_back(row-1);
                ans.push_back(c);
                break;
            }
            if(c>col-1){
                ans.push_back(r);
                ans.push_back(col-1);
                break;
            }
            if(mat[r][c]==0){
                if(wheres==5) q.push({r,c+1,5});
                else if(wheres==-5) q.push({r,c-1,-5});
                else if(wheres==10) q.push({r-1,c,10});
                else if(wheres==-10) q.push({r+1,c,-10});
            }
            else{
                if(wheres==5) q.push({r+1,c,-10});
                else if(wheres==-5) q.push({r-1,c,10});
                else if(wheres==-10) q.push({r,c-1,-5});
                else if(wheres==10) q.push({r,c+1,5});
                mat[r][c]=0;
            }
        }
        return ans;
    }
};