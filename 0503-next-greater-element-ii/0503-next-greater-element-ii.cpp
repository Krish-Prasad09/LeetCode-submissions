class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> st;
        for(int j=2*nums.size()-1; j>=0; j--){
            int i=j%nums.size();
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(nums[i]);
        }
    return ans;
    }
    
};