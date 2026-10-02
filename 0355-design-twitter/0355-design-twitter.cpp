class Twitter {
public:

    // {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    unordered_map<int, unordered_set<int>> mp;

    int cnt = 0;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({cnt++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> ans;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > tq;

        // own tweets
        for(auto &x : tweets[userId]) {
            tq.push(x);

            if(tq.size() > 10)
                tq.pop();
        }

        // followed users' tweets
        for(int followee : mp[userId]) {

            for(auto &x : tweets[followee]) {

                tq.push(x);

                if(tq.size() > 10)
                    tq.pop();
            }
        }

        while(!tq.empty()) {
            ans.push_back(tq.top().second);
            tq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};