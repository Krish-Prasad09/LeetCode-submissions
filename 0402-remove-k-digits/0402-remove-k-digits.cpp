class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        stack<int> st;
        int cnt=0;
        st.push(num[0]-'0');
        for(int i=1; i<n; i++){
            int val=num[i]-'0';
            while(!st.empty() && val < st.top() && cnt < k){
                st.pop();
                cnt++;
            }
            st.push(val);
        }
    while(cnt < k) {
    st.pop();
    cnt++;
}
    string ans="";
    while(!st.empty()){
        auto topi=st.top();
        st.pop();
        ans+=(topi+'0');
    }
        while(!ans.empty() && ans.back() == '0') {
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());

    // If we removed everything (or if the answer was all zeros), return "0"
    if (ans.empty()) {
        return "0";
    }

    return ans;
    }
};