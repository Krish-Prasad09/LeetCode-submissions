class Solution {
public:
int f(int l, int r,int n, string &s){
    if (l < 0 || r >= n) return 0;
    if(s[l]==s[r]){
        return 1+f(l-1,r+1,n,s);
    }
    return 0;
}
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0; i<n; i++){
            ans+=f(i,i,n,s);
            ans+=f(i,i+1,n,s);
        }
        return ans;
    }
};