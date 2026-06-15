class Twitter {
    // map<int,set<int>> friends; //int is userId and set is user ko followees
    int curr=0;
    // priority_queue<vector<int>> timeline; //{time, tweetId, userId}
    unordered_map<int,unordered_set<int>> friends; //Ids are unique
    vector<pair<int,int>> posts;
public:
    Twitter() {
        // friends.clear();
        // curr=0;
        // timeline=priority_queue<vector<int>>(); //Naya empty priority queue bana diya.
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
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

        for(int i=posts.size()-1; i>=0 && n<10; i--){
            if(posts[i].first==userId || friends[userId].count(posts[i].first)){
                ans.push_back(posts[i].second);
                n++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
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

