class Solution {
public:
    string processStr(string s) {
        int n=s.length();
        string result="";
        for(int i=0; i<n; i++){
            if(s[i]=='#') result+=result;
            else if(s[i]=='%') reverse(result.begin(),result.end());
            else if(s[i]=='*'){
                if(!result.empty())result.pop_back();
                else continue;
            }
            else result.push_back(s[i]); 
        }
        return result;
    }
};