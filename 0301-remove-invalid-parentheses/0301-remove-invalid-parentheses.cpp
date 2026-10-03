class Solution {
public:

    bool valid(string &s) {
        int balance = 0;

        for(char c : s) {
            if(c == '(') {
                balance++;
            }
            else if(c == ')') {
                balance--;

                if(balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    void solve(int i, string &s, string &curr, 
               vector<string> &ans, int &maxLen) {

        // Base case
        if(i == s.length()) {

            if(valid(curr)) {

                if(curr.length() > maxLen) {
                    ans.clear();
                    ans.push_back(curr);
                    maxLen = curr.length();
                }
                else if(curr.length() == maxLen) {
                    ans.push_back(curr);
                }
            }

            return;
        }

        // TAKE
        curr.push_back(s[i]);
        solve(i + 1, s, curr, ans, maxLen);
        curr.pop_back();

        // NOT TAKE
        if(s[i] == '(' || s[i] == ')') {
            solve(i + 1, s, curr, ans, maxLen);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;
        string curr;
        int maxLen = 0;

        solve(0, s, curr, ans, maxLen);

        // Remove duplicates
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};