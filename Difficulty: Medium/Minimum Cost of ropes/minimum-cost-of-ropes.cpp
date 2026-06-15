class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n=arr.size();
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        int cost=0;stack<int>st;
        while(!pq.empty()){
            
            if(st.size()==0){
                st.push(pq.top());
                pq.pop();
            }
            else{
                int value=st.top();
                st.pop();
                int pqv=pq.top();
                pq.pop();
                pqv+=value;
                pq.push(pqv);
                cost+=pqv;
            }
        }
        return cost;
    }
};