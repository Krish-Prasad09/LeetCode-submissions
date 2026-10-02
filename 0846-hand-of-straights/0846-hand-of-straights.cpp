class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n % groupSize != 0)
            return false;
        sort(hand.begin(),hand.end());
        priority_queue<int> pq;
        map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[hand[i]]++;
        }
        int g1=0;
        for(auto it = mp.begin(); it != mp.end(); ){
            if(it->second != 0 && (pq.empty() || pq.top()+1 == it->first)){
                pq.push(it->first);
                it->second--;
                if(pq.size()==groupSize){
                    g1++;
                    while(!pq.empty()) pq.pop();
                    it=mp.begin();
                    continue;
                }
            }
            it++;
        }
        return g1==n/groupSize;
    }
};