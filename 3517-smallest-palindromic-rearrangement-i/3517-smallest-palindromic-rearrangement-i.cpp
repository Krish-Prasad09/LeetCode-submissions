class Solution {
public:
// bool checkP(string s){
//     int l=0, r=s.length()-1;
//     while(l<=r && l<s.length() && r>=0){
//         if(s[l]!=s[r]) return false;
//         l++;
//         r--;
//     }
//     return true;
// }
    string smallestPalindrome(string s) {
        int n=s.length();
        priority_queue<char, vector<char>, greater<char>> pq1;
        priority_queue<char, vector<char>, greater<char>> pq2;
        for(int i=0; i<n/2; i++){
            pq1.push(s[i]);
            if(i!=n-i-1) pq2.push(s[n-i-1]);
        }
        int n1=pq1.size();
        int n2=pq2.size();
        string ans(n, '#'); 
        if (n % 2 != 0) {
            ans[n / 2] = s[n / 2];
        }
        int i=0;
        while(!pq1.empty() && !pq2.empty()){
            ans[i]=pq1.top();
            pq1.pop();
            ans[n-i-1]=pq2.top();
            pq2.pop();
            i++;
        }
        while(!pq1.empty()){
            ans[i]=pq1.top();
            i++;
            pq1.pop();
        }
        while(!pq2.empty()){
            ans[n-i-1]=pq2.top();
            pq2.pop();
            i++;
        }
        return ans;
    }
};