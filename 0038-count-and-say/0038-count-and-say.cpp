class Solution {
public:
string RLE(string s){
    int n=s.length();
    if(n==1) return "1"+s;
    string ans="";
    // if(dupliicate) return to_string(n)+s[0];
    // else{string ans="";
    //     for(int i=0; i<n; i++){
    //         ans+="1"+s[i];
    //     }
    //     return ans;
    // }

    int i=0;
    while(i<n){
        int cnt=1;
        while(i+1<n && s[i]==s[i+1]){
            cnt++;
            i++;
        }
        ans += to_string(cnt);
        ans += s[i];

        i++;
    }
    return ans;
}
    string countAndSay(int n) {
        if(n==1) return "1";
        string ans="";
        ans+=RLE(countAndSay(n-1));
        return ans;
    }
};