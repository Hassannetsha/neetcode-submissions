class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>>posts;
    unordered_map<int,set<int>>follower;
    int time;
    Twitter() {  
        time = 0;
    }
    void postTweet(int userId, int tweetId) {
        posts[userId].emplace_back(time++, tweetId);
    }
    vector<int> getNewsFeed(int userId) {
        int cnt = 0;
        vector<int>ans;
        int j = 0;
        vector<int>followers;
        for(auto it:follower[userId]){
            followers.push_back(it);
        }
        int tempuserId = userId;
        if(j<followers.size())
            userId = followers[j++];
        priority_queue<pair<int,int>>pq;
        while(true){
            for(int i = posts[userId].size()-1;i>=0;i--){
                pq.push(posts[userId][i]);
            }
            if(j<followers.size())
                userId = followers[j++];
            else if(j==followers.size()&&userId!=tempuserId)
                userId = tempuserId;
            else
                break;
        }
        vector<int>result;
        while(!pq.empty()&&cnt<10){
            result.push_back(pq.top().second);
            cnt++;
            pq.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};