class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        string s=to_string(n);
        int m=s.length();
        long long sum=0;
        string p;
        for(int i=0; i<m; i++){
            if(s[i]=='0') continue;
            sum+=s[i]-'0';
            p.push_back(s[i]);
        }
        long long num=stoll(p);
        return num*sum;
    }
};