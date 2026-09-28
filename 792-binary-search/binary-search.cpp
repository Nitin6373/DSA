class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int Mid = (low + high) / 2;

            if (nums[Mid] == target) {
                return Mid;
            }

            if (nums[Mid] > target) {
                high = Mid - 1;
            } else {
                low = Mid + 1;
            }
        }

        return -1;
    }
};