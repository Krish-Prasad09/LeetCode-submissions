class Solution {
public:
    char processStr(string s, long long k) {
        int m=s.length();
        long long len=0;
        for(int i=0; i<m; i++){
            if(s[i]=='*') {
                if (len > 0) len-=1; // Only decrement if length > 0. Do nothing otherwise.
            }
            else if(s[i]=='#') len+=len;
            else if(s[i]=='%') continue;
            else len+=1;
        }
        if(k >= len) return '.';
        for(int i=m-1; i>=0; i--){
            if(s[i]=='*' ) len+=1;
            else if(s[i]=='#'){
                len/=2;
                if(len!=0)k=k%len;
            } 
            else if(s[i]=='%') k=len-k-1;
            else{
                if(len>0)len-=1;

                if(k==len) return s[i];
            } 
        }
        return '.';
    }
};