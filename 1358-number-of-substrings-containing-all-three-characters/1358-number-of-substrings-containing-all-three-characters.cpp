class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int cnt=0;int l=0;
        map<int,int> mp;
        for(int i=0; i<n; i++){
            if(s[i]=='a') mp[0]++;
            else if(s[i]=='b') mp[1]++;
            else if(s[i]=='c') mp[2]++;
            while(mp[0]>0 && mp[1]>0 && mp[2]>0){
                cnt+=n-i;
                if(s[l]=='a') mp[0]--;
                else if(s[l]=='b') mp[1]--;
                else if(s[l]=='c') mp[2]--;
                l++;
            }
        }
        return cnt;
    }
};