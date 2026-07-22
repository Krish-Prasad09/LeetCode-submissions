class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(arr[i]>=0){
                st.push(arr[i]);
            }
            else if(arr[i]<0){
                if(!st.empty() && abs(arr[i])<st.top()) continue;
                else if(!st.empty() && abs(arr[i])==st.top()){
                    st.pop();
                    continue;
                }
                while(!st.empty() && st.top()>0 && st.top()<abs(arr[i])){
                    st.pop();
                }
                if(st.empty() || st.top()<0) st.push(arr[i]);
                else if (st.top() == abs(arr[i]))
                st.pop();
            }
        }
        vector<int> v;

        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};