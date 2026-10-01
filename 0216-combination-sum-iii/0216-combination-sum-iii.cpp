class Solution {
public:
    void solve(int ind,int k,int n,int sum,
               vector<int>& curr,vector<vector<int>>& ans) {

        if(curr.size()==k) {
            if(sum==n)
                ans.push_back(curr);
            return;
        }

        if(ind>9 || sum>n)
            return;

        // Take
        curr.push_back(ind);
        solve(ind+1,k,n,sum+ind,curr,ans);
        curr.pop_back();

        // Not Take
        solve(ind+1,k,n,sum,curr,ans);
    }

    vector<vector<int>> combinationSum3(int k,int n) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(1,k,n,0,curr,ans);

        return ans;
    }
};