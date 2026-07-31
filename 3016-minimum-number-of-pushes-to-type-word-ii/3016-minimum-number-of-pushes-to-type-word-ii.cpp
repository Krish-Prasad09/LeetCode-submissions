class Solution {
    public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for (char c : word) 
            freq[c - 'a']++;
        auto cmp = [](const int& a,const int& b){
            return a < b;
        };
        sort(freq.begin(),freq.end(),cmp);
        for(int f : freq){
            cout << f << "\t";
        }
        cout << endl;
        int ans = 0;
        for (int i = 25; i >= 0 && freq[i] > 0; i--) 
            ans += freq[i] * ((25 - i) / 8 + 1);
        
        return ans;
    }
};