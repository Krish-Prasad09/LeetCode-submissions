class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        unordered_map<char,int>mp;
        for(int i=0; i<n; i++){
            char s=digits[i]+'0';
            mp[s]++;
        }
        int ans=0;

        for(int i=100; i<1000; i++){
            string s=to_string(i);
            unordered_map<char, int> temp = mp;
            bool hai=true;
            for(auto &it:s){
                if(temp[it]==0){
                    hai=false;
                    break;
                }
                temp[it]--;
            }
            if(hai && i%2 ==0) ans++;
        }

        return ans;
    }
};