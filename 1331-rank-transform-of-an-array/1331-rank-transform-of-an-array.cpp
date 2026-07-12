class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans=arr;
        sort(ans.begin(),ans.end());
        int n=arr.size();
        unordered_map<int,int> mp;
        int prev=0;
        for(int i=0; i<n; i++){
            if(mp.find(ans[i])==mp.end()){
                mp[ans[i]]=prev+1;
                prev++;
            }
        }
        for(auto &it:arr){
            it=mp[it];
        }
        return arr;
    }
};