class Solution {
public:
    int findMin(vector<int>& nums) {
        int beg = 0;
        int end = nums.size() - 1;
        int res = nums[0];

        while (beg <= end) {
            if(nums[beg] < nums[end]) {
                res = min(res, nums[beg]);
                break;
            }
            int mid = beg + (end - beg)/2;
            res = min(res, nums[mid]);
            if(nums[beg] > nums[mid]) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        return res;
    }
};