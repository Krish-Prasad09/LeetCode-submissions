class Solution {
public:
    void func(int open, int close, string curr, vector<string> &ans, int n){
        if(curr.length()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n) func(open+1, close, curr+"(", ans,n);
        if(close<open) func(open, close+1, curr+")", ans,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func(0, 0, "", ans, n);
        return ans;
    }
};