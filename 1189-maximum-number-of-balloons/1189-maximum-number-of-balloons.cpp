class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> hash(26,0);
        int n=text.length();
        for(int i=0; i<n; i++){
            hash[text[i]-'a']++;
        }
        int mini=INT_MAX, mini2=INT_MAX;
        for(int i=0; i<26; i++){
            if(i==1 || i==0 || i=='n'-'a') mini=min(mini,hash[i]);
            else if(i=='l'-'a' || i=='o'-'a') mini2=min(mini2,hash[i]);
        }
        if(mini<1 || mini2<2) return 0;
        if(mini<mini2/2) return mini;
        else return mini2/2;
    }
};