class Twitter {
    // map<int,set<int>> friends; //int is userId and set is user ko followees
    int curr=0;
    // priority_queue<vector<int>> timeline; //{time, tweetId, userId}
    unordered_map<int,unordered_set<int>> friends; //Ids are unique
    unordered_map<int, vector<pair<int,int>>> posts;
public:
    Twitter() {
        // friends.clear();
        // curr=0;
        // timeline=priority_queue<vector<int>>(); //Naya empty priority queue bana diya.
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({curr++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // priority_queue<vector<int>> userTimeline=timeline;
        int n=0;
        // while(!userTimeline.empty() && n<10){
        //     auto topTweet=userTimeline.top();
        //     userTimeline.pop();
        //     if(topTweet[2]==userId || friends[userId].count(topTweet[2])){
        //         ans.push_back(topTweet[1]);
        //         n++;
        //     }
        // }

        // for(int i=posts.size()-1; i>=0 && n<10; i--){
        //     if(posts[i].first==userId || friends[userId].count(posts[i].first)){
        //         ans.push_back(posts[i].second);
        //         n++;
        //     }
        // }
        // return ans;

        priority_queue<vector<int>> pq;
        vector<int> ans;

        // user's own latest tweet
        if (!posts[userId].empty()) {
            int idx = posts[userId].size() - 1;

            pq.push({
                posts[userId][idx].first,   // timestamp
                posts[userId][idx].second,  // tweetId
                userId,
                idx
            });
        }

        // latest tweet of each followee
        for (auto followee : friends[userId]) {

            if (!posts[followee].empty()) {

                int idx = posts[followee].size() - 1;

                pq.push({
                    posts[followee][idx].first,
                    posts[followee][idx].second,
                    followee,
                    idx
                });
            }
        }

        while (!pq.empty() && ans.size() < 10) {

            auto top = pq.top();
            pq.pop();

            int tweetId = top[1];
            int uid = top[2];
            int idx = top[3];

            ans.push_back(tweetId);

            // push previous tweet of same user
            if (idx > 0) {

                pq.push({
                    posts[uid][idx - 1].first,
                    posts[uid][idx - 1].second,
                    uid,
                    idx - 1
                });
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;

        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;

        friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */