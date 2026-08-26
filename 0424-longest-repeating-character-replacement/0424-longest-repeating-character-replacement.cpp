class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0;
        int maxi = 0;
        int max_freq = 0; // Tracks the count of the most frequent character in the current window
        unordered_map<char, int> mp; 
        
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
            // Update the maximum frequency seen in our window so far
            max_freq = max(max_freq, mp[s[i]]);
            
            // If the characters we NEED to replace exceed k, shrink the window from the left
            if ((i - l + 1) - max_freq > k) {
                mp[s[l]]--;
                l++;
            }
            
            maxi = max(maxi, i - l + 1);
        }
        
        return maxi;
    }
};