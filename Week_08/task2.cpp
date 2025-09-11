class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> subarray;
        int start = 0;
        int maxSum = 0;
        int subarraySum = 0;

        for (int i = 0; i < nums.size(); i++) {
            while(subarray.count(nums[i])) {
                subarray.erase(nums[start]);
                subarraySum -= nums[start];
                start++;
            }
            subarray.insert(nums[i]);
            subarraySum += nums[i];
            maxSum = max(maxSum, subarraySum);
        }
        return maxSum;
    }
};