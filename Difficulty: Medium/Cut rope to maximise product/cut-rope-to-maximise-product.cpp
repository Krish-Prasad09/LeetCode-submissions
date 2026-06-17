class Solution {
  public:
  int memo[60];
  int f(int n){
      if(n==2) return 1;if (memo[n] != -1) return memo[n];
      if(n<2) return 0;
      int maxi=0;
        for(int i=1; i<n; i++){
            maxi=max(maxi,max(i,f(i))*max(n-i,f(n-i)));
        }
    return memo[n] = maxi;
  }
    int maxProduct(int n) {
        // code here
        fill(begin(memo), end(memo), -1);
        return f(n);
        
    }
};