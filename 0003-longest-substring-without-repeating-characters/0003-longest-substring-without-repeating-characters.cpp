class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int cnt=0;
        int maxi=INT_MIN;
        vector<int> hash(256,0);
        if(s.empty()) return 0;
        int l=0;
        for(int i=0; i<n; i++){
            hash[s[i]]++;
            while(hash[s[i]]>1){
                cnt--;
                hash[s[l]]--;
                l++;
            }
            if(!(hash[s[i]]>1)){
                cnt++;
                maxi=max(maxi,i-l+1);
            }
        }
        return maxi;
    }
};