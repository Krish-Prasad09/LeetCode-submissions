class Solution {
    public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for (char c : word) 
            freq[c - 'a']++;
        auto cmp = [](const int& a,const int& b){
            return a < b;
        };
        int n = 10;
        vector<int> q(n,0);
        for(int i =0;i<n;i++){
            q[i] = i;
        }
        sort(q.begin(),q.end(),cmp);
        for(int k : q){
            cout << k << "\t";
        }
        cout << endl;
        sort(freq.begin(),freq.end(),cmp);
        // for(int f : freq){
        //     cout << f << "\t";
        // }
        cout << endl;
        int ans = 0;
        for (int i = 25; i >= 0 && freq[i] > 0; i--) 
            ans += freq[i] * ((25 - i) / 8 + 1);
        
        return ans;
    }
};


// auto cmp = [](){
//     return a>b ; a has lesser pq
// }
// a<b b has lesser
// pb<int,vector<int>,decltype(cmp)> pq(cmp);