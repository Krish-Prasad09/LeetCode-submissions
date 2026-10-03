class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        int open=0, close=0;
        int res=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
            if(close>open){
                open=0;
                close=0;
            }
            else if(close==open){
                res=max(res,open+close);
            }
        }
        open=0;
        close=0;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
            if(close<open){
                open=0;
                close=0;
            }
            else if(close==open){
                res=max(res,open+close);
            }
        }
        return res;
    }
};