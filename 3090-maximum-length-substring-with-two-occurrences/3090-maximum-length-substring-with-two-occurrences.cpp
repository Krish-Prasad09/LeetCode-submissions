class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int l=0;
        int maxi=0;
        unordered_map<char,int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
            while(mp[s[i]]>2 && l<n){
                mp[s[l]]--;
                l++;
            }
            maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};