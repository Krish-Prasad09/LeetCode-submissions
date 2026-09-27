class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;

        for (int i = 0; i < s.length(); i++) {

            // 1. Store index of '('
            if (s[i] == '(') {
                st.push(i);
            }

            // 2. When ')' comes
            else if (s[i] == ')') {

                int open = st.top();
                st.pop();

                // 3. Reverse characters inside the brackets
                reverse(s.begin() + open + 1, s.begin() + i);
            }
        }

        // 4. Remove '(' and ')'
        string ans;

        for (char c : s) {
            if (c != '(' && c != ')') {
                ans.push_back(c);
            }
        }

        return ans;
    }
};