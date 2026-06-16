class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        vector<int> prefixXor(n,arr[0]);
        for(int i=1; i<n; i++){
            prefixXor[i]=prefixXor[i-1] ^ arr[i];
        }
        unordered_map<int,int> mp;mp[0] = 1;
        int count=0;
        for(int i=0; i<n; i++){
            int value=prefixXor[i]^k;
            if (mp.find(value) != mp.end()) {
                count += mp[value];
            }
            mp[prefixXor[i]]++;
        }
        return count;
        
    }
};