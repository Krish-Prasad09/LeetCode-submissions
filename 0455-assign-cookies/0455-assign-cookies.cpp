class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        int cn=g.size();
        int sn=s.size();
        sort(s.begin(),s.end());
        int l=0;
        int cnt=0;
        for(int i=0; i<sn; i++){
            if(l<cn && s[i]>=g[l]){
                cnt++;
                l++;
            }
            else continue;
        }
        return cnt;
    }
};