class Solution {
public:
    int reverse(int x) {
        string s=to_string(x);
        int ans=0;
        if(s[0]=='-'){
            std::reverse(s.begin(),s.end());
            s.pop_back();
            try{
                ans=stoi(s);
            } catch(...) {
                return 0;
            }
            return ans*(-1);
        }
        else{
            std::reverse(s.begin(),s.end());
            try{
                ans=stoi(s);
                
            }catch(...) {
                return 0;
            }
            return ans*(1);
        }
    }
};