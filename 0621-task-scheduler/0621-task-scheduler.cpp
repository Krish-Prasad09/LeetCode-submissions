class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        unordered_map<char,int> mp;
        for(auto it:tasks) mp[it]++;
        priority_queue<int> pq;
        for(auto &it:mp){
            pq.push(it.second);
        }
        queue<pair<int,int>> q; // {freq, availableTime}
        int time=0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int freq=pq.top();
                pq.pop();
                freq--;
                if(freq>0) q.push({freq, time + n});
            }
            if(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};