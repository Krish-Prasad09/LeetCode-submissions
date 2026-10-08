class Solution {
public:
    string removeOuterParentheses(string s) {
        int l=0; 
        int n=s.length();
        int cnt=0;
        string ans;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt==0){
                s[l]='*';
                l=i+1;
                s[i]='*';
            }
        }
        for(auto it:s){
            if(it!='*') ans+=it;
        }
        return ans;
    }
};