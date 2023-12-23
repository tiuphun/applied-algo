class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int cur_max = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            cur_max = max(nums[i], cur_max + nums[i]);
            max_so_far = max(max_so_far, cur_max);
        }
        return max_so_far;
    }
};