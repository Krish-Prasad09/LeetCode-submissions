class Solution {
public:
    bool f(int si, int pi, string &s, string&p){
        if (pi == p.length()) return si == s.length();

        if(pi + 1 < p.length() && p[pi+1] == '*'){
        
        if(si < s.length() && (p[pi] == s[si] || p[pi] == '.'))
            return f(si+1, pi, s, p) || f(si, pi+2, s, p);

        return f(si, pi+2, s, p);   // <-- added
    }
        if(si < s.length() && (p[pi] == s[si] || p[pi] == '.'))
        return f(si+1, pi+1, s, p);

    return false;
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        return f(0,0,s,p);
    }
};