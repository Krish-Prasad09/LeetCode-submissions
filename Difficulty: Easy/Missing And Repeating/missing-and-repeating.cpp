class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n=arr.size();
        long long sums=0,sumsq=0;
        for(int i=0; i<n; i++){
            sums+=arr[i];
            sumsq+=1LL*(arr[i])*arr[i];
        }
        long long ans1=sums- (n*(n+1))/2;
        long long ans2=sumsq- (n*(n+1)*(2*n+1))/6;
        
        long long R=((ans2)/ans1 +ans1)/2;
        long long m=((ans2)/ans1 -ans1)/2;
        return {R,m};
    }
};