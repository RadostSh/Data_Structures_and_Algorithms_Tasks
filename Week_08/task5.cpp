class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int, vector<int>> el;
        vector<int> res(queries.size(), -1);

        for(int i = 0; i < nums.size(); i++) {
            el[nums[i]].push_back(i);
        }

        if(el.count(x) == 0) {
            return res;
        }

        for(int i = 0; i < queries.size(); i++) {
            if(queries[i] <= el[x].size()) {
                res[i] = el[x][queries[i] - 1];
            }
        }
        return res;
    }
};