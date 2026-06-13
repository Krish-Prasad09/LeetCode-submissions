class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n1=a.length();
        int n2=b.length();
        string ans="";
        int cnt=0;
        while(ans.size()<n2){
            ans+=a;
            cnt++;
        }
        if(ans.find(b)!=string::npos) return cnt;
        ans+=a; cnt++;
        if(ans.find(b)!=string::npos) return cnt;
        return -1;
    }
};