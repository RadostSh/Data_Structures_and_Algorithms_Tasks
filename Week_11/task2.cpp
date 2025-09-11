class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        size_t V = friends.size();
        vector<bool> visited(V, false);
        queue<int> q;
        int currLevel = 0;

        visited[id] = true;
        q.push(id);

        while(!q.empty() && currLevel < level) {
            int len = q.size();
            for(int i = 0; i < len; i++) {
                int curr = q.front();
                q.pop();

                for(auto& e : friends[curr]) {
                    if(!visited[e]) {
                        visited[e] = true;
                        q.push(e);
                    }
                }
            }
            currLevel++;
        }

        if(currLevel != level) {
            return {};
        }

        unordered_map<string, int> videoCount;
        while(!q.empty()) {
            int frID = q.front();
            q.pop();

            for(auto& e : watchedVideos[frID]) {
                videoCount[e]++;
            }
        }

        vector<pair<int, string>> sortedVideo;
        for(auto& v : videoCount) {
            sortedVideo.push_back({v.second, v.first});
        }

        sort(sortedVideo.begin(), sortedVideo.end(), [](const pair<int, string>& a, const pair<int, string>& b){return (a.first != b.first) ? (a.first < b. first):(a.second < b.second);});

        vector<string> result;
        for(auto& v : sortedVideo) {
            result.push_back(v.second);
        }

        return result;
    }
};