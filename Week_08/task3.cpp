class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());

        unordered_map<int,int> num;
        for(int i = 0; i < nums.size(); ++i) {
            num[nums[i]] = i;
        }

        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); ++i) {
            int target = -nums[i];
            for(int j = i + 1; j < nums.size(); ++j) {
                if(num.count(target - nums[j]) && num[target - nums[j]] > j) {
                    res.push_back({nums[i], nums[j], target - nums[j]});
                }
                j = num[nums[j]];
            }
            i = num[nums[i]];
        }
        return res;
    }
};