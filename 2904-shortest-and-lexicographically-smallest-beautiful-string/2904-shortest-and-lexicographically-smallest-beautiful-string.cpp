class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        int start=0,end=0;
        int mini=INT_MAX;
        int l=0,cnt=0;
        priority_queue<string,vector<string>,greater<string>> pq;
        while(s[l]!='1' && l<n) l++;
        while(l < n && s[l] != '1') l++;
        int i=l;
        while(true){
            if(i>=n || l>i || l>=n) break;
            if(s[i]=='1'){
                cnt++;
                i++;
            }
            else if(s[i]=='0') i++;
            while(cnt>k){
                cnt--;
                l++;
                while(s[l]!='1') l++;
            }
            if(cnt==k){
                int len=i-l;
                if(len < mini){
                    while(!pq.empty())
                        pq.pop();

                    mini = len;
                    pq.push(s.substr(l, len));
                }
                else if(len == mini){
                    pq.push(s.substr(l, len));
                }
            }
        }
        if(pq.empty()) return "";
        return pq.top();
    }
};