class Solution {
public:
    string intToRoman(int num) {
        map<int, char> mp;
        mp.insert({1, 'I'});
        mp.insert({5, 'V'});
        mp.insert({10, 'X'});
        mp.insert({50, 'L'});
        mp.insert({100, 'C'});
        mp.insert({500, 'D'});
        mp.insert({1000, 'M'});

        string p=to_string(num);
        int m=p.length();

        string result="";
        while(true){
            if(num<=0) break;
            string s=to_string(num);
            int n=s.length();
            char next;
            string ans="";
            ans+=s.front();
            bool isf=(ans=="4");
            bool isn=(ans=="9");
            while(ans.length() < n){
                ans += "0";
            }
            int no1=stoi(ans);
            char prev='I';
            char prev2='I';
            int previ=0;
            int nexti=INT_MAX;
            
            for(auto it:mp){
                if(it.first<=no1) {
                    prev2=prev;
                    prev=it.second;
                    previ=it.first;
                }
                else{
                    next=it.second;
                    break;
                }
            }
            if(isf){
                result += prev;
                result += next;
                num-=no1;
                continue;
            }
            else if(isn){
                result += prev2;
                result += next;
                num-=no1;
                continue;
            }
            result+=prev;
            num-=previ;
            continue;
        }
        return result;
    }
};