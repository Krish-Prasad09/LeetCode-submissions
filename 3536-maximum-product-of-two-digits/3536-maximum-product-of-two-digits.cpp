class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        int no=s.length();
        return (s[no-1]-'0')*(s[no-2]-'0');
    }
};