class Solution {
public:
    unordered_map<char,string> mp={
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };

void solve(int ind, string digits, vector<string>&ans, string curr){
    if(ind>=digits.size()){
        ans.push_back(curr);
    }
    string s=mp[digits[ind]];
    int sn=s.length();
    for(int i=0; i<sn; i++){
        solve(ind+1,digits,ans,curr+s[i]);
    }
}
    vector<string> letterCombinations(string digits) {
        int n=digits.length();
        vector<string> ans;
        solve(0,digits,ans,"");
        return ans;
    }
};