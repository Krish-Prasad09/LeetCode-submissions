class Solution {
public:
    void solve(int i,vector<int>& candidates,int sum,int target,
               vector<int> temp,vector<vector<int>>& ans) {

        if(sum==target) {
            ans.push_back(temp);
            return;
        }

        if(i==candidates.size() || sum>target)
            return;

         // Not Take
        solve(i+1,candidates,sum,target,temp,ans);

        // Take
        temp.push_back(candidates[i]);
        solve(i,candidates,sum+candidates[i],target,temp,ans);

       
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0,candidates,0,target,temp,ans);

        return ans;
    }
};