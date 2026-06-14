class Solution {
  public:
    void replaceWithRank(vector<int>& arr) {
        // code here
        vector<int> sorted=arr;
        sort(sorted.begin(),sorted.end());
        unordered_map<int,vector<int>>mp;
        for(int i=0; i<sorted.size(); i++){
            mp[sorted[i]].push_back(i);
        }
        for(int i=0; i<sorted.size(); i++){
            int value=arr[i];
            arr[i]=mp[arr[i]][0];
            mp[value].erase(mp[value].begin());
        }
    }   
};