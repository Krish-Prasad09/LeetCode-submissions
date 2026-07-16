class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1){
            if(nums[0]==k) return 1;
            else return 0;
        }
        int cnt=0;
        vector<int> pref;
        pref.push_back(0);
        int prefS=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0; i<n; i++){
            prefS+=nums[i];
            pref.push_back(prefS);
            if(mp.find(prefS-k) !=mp.end()){
                cnt += mp[prefS-k];
            }
            
            mp[prefS]++;
            
        }

        return cnt;
    }
};