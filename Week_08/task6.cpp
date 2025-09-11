class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> values;
        for(int i = 0; i < nums.size(); i++) {
            if(values.count(target - nums[i])) {
                return {values[target - nums[i]], i};
            }
            values[nums[i]] = i;
        }
        return {};
    }
};