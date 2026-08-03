class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int sum = 0;
        vector<vector<int>> Result;
        for (int i = 0; i < nums.size() - 2; i++) {
            left = i + 1;
            right = nums.size() - 1;
            sum = -nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            while (left < right) {
                if ((nums[left] + nums[right]) == sum) {
                    Result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right &&
                           (nums[left] == nums[left - 1])) {
                        left++;
                    }
                    while (left < right && (nums[right] == nums[right + 1])) {
                        right--;
                    }
                } else if ((nums[left] + nums[right]) > sum) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return Result;
    }
};