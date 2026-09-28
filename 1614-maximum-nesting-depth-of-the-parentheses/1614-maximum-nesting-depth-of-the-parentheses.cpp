class Solution {
public:
    int maxDepth(string s) {
        int maxi=INT_MIN;
        int n=s.length();
        int level=0;
        for(int i=0; i<n; i++){
            if(s[i]=='(') {
                level++;
                maxi=max(level,maxi);
                continue;
            }
            else if(s[i]==')'){
                level--;
                continue;
            }
            else maxi=max(level,maxi);
        }
        return maxi;
    }
};