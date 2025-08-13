class Twitter {
    // 'users' stores tweets for each user:
    // Key: userID
    // Value: vector of {order, tweetID}
    // 'order' is a timestamp to know when the tweet was posted
    map<int, vector<pair<int, int>>> users;
    // 'followers' stores follow relationships:
    // Key: followerID
    // Value: set of followeeIDs (people they follow)
    unordered_map<int, set<int>> followers;
    // Global counter to assign increasing order (timestamp) to tweets
    int order = 0;
public:
    // Constructor (currently does nothing specific)
    Twitter() {
    }
    // Post a tweet by a user
    void postTweet(int userId, int tweetId) {
        // Append a new tweet with current 'order' and tweetId
        // Then increment 'order' for the next tweet
        users[userId].push_back({order++, tweetId});
    }
    // Get the 10 most recent tweet IDs in the user's news feed
    vector<int> getNewsFeed(int userId) {
        // Max-heap (priority queue) to store tweets in order of recency
        // pair<int,int> → {order, tweetId}, ordered by 'order' automatically
        priority_queue<pair<int, int>> feed;
        vector<int> ans; // final list of tweet IDs
        // Add this user's own tweets to the feed
        for (auto i : users[userId]) {
            feed.push(i);
        }
        // Add tweets from each followee of this user
        for (auto i : followers[userId]) {
            for (auto j : users[i]) {
                feed.push(j);
            }
        }
        // Extract tweets from the heap, most recent first
        while (!feed.empty()) {
            ans.push_back(feed.top().second); // take tweetID
            feed.pop();
        }
        // Limit to at most 10 tweets
        if (ans.size() > 10)
            ans.resize(10);
        return ans;
    }
    // Make followerId follow followeeId
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    // Make followerId unfollow followeeId
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
