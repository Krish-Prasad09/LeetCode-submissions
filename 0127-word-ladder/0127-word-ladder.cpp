class Solution {
public:
bool beta(string s1, string s2){
    int i=0,j=0;
    int n=8,cnt=0;;
    while(i<n && j<n){
        if(s1[i]!=s2[j]) cnt++;
        i++; j++;
    }
    return cnt==1;
}
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        bank.push_back(startGene);
        int n=bank.size();
        unordered_map<string, vector<string>> adj;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && beta(bank[i],bank[j])){
                    adj[bank[i]].push_back(bank[j]);
                }
            }
        }
        queue<tuple<string,int>> q;
        q.push({startGene,1});
        unordered_set<string> vis;
        vis.insert(startGene);
        int mini=INT_MAX;
        while(!q.empty()){
            auto [node,steps]=q.front();
            q.pop();
            if(node==endGene){
                mini=min(mini,steps);
            }
            for(auto &it:adj[node]){
                if(!vis.count(it)) {
                    vis.insert(it);
                    q.push({it, steps + 1});
                }
            }
        }
        return (mini==INT_MAX)?0:mini;

    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return minMutation(beginWord,endWord,wordList);
    }

};