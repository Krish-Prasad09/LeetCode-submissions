class Solution {
  public:
  void insert(stack<int> &st,int topi){
      if(st.empty()){
          st.push(topi);
          return;
      }
      int top=st.top();
      st.pop();
      insert(st,topi);
      st.push(top);
      
  }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty() || st.size()==1)return;
        int topi=st.top();
        st.pop();
        reverseStack(st);
        insert(st,topi);
        
    }
};