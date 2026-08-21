class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int two = INT_MIN;

        for(int i = n-1; i >= 0; i--) {

            if(nums[i] < two)
                return true;

            while(!st.empty() && st.top() < nums[i]) {
                two = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};