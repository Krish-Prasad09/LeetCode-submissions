class Solution {
public:
    bool isSubstring(string s, string word){
        int n=word.length();
        int m=s.length();
        if(m>n) return false;
        else if(m==n) return s==word;
        for(int i=0; i<=n-m; i++){
            int cnt=0;
            for(int j=0; j<m; j++){
                if(s[j]!=word[i+j]) continue;
                else cnt++;;
            }
            if(cnt==m) return true;
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            string s=patterns[i];
            if(isSubstring(s,word)) cnt++;
            else continue;
        }
        return cnt;
    }
};