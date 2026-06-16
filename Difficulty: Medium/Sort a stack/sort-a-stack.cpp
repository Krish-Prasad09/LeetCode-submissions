class Solution {
  public:
    void sortStack(stack<int> &st) {
        // code here
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        while(!ans.empty()){
            st.push(ans.back());
            ans.pop_back();
        }
    }
};
