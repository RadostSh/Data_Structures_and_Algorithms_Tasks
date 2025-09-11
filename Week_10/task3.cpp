class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, bool> m;

        for(auto& n : edges) {
            if(m.count(n[0])) {
                return n[0];
            }
            if(m.count(n[1])) {
                return n[1];
            }
            m[n[0]] = true;
            m[n[1]] = true;
        }
        return -1;
    }
};