class Solution {
public:
bool check(unordered_map<char,int>& smp,
               unordered_map<char,int>& tmp){

        for(auto it:tmp){
            if(smp[it.first] < it.second)
                return false;
        }

        return true;
    }
    string minWindow(string s, string t) {
        int n=s.length();
        unordered_map<char,int> tmp;
        for(int i=0; i<t.size(); i++){
            tmp[t[i]]++;
        }
        int startindex=0,endindex=0;
        unordered_map<char,int> smp;
        int l=0;
        int mini=INT_MAX;
        while(l<n && tmp.find(s[l])==tmp.end()) l++;
        for(int i=l; i<n; i++){
            if( tmp.find(s[i])!=tmp.end() ){
                smp[s[i]]++;
            }
            while(check(smp,tmp)){
                if(mini>i-l+1){
                    mini=min(mini,i-l+1);
                    startindex=l;
                    endindex=i;
                }
                smp[s[l]]--;
                l++;
                while(l<n && tmp.find(s[l])==tmp.end()) l++;
            }
        }
        if(mini!=INT_MAX) return s.substr(startindex,endindex-startindex+2-1);
        else return "";
    }
};