class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.length();
        stack<char> st;
        unordered_map<char,int> hash;
        for(auto it:s) hash[it]++;
        string ans="";
        unordered_map<char,int> mp;
        for(int i=0; i<n; i++){
            hash[s[i]]--;
            if(mp.count(s[i])) continue;
            if(st.empty() || s[i]>st.top()){
                mp[s[i]]++;
                st.push(s[i]);
            }
            else{
                while(!st.empty() && st.top()>s[i] && hash[st.top()]>0){
                    mp[st.top()]--;
                    if(mp[st.top()]==0) mp.erase(st.top());
                    st.pop();
                }
                if(mp.size()<hash.size()) {
                    st.push(s[i]);
                    mp[s[i]]++;
                }
                else continue;
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};