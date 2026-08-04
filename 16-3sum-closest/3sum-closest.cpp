class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int Result = INT_MAX;
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == target) {
                    Result = sum;
                    return Result;
                } else if (sum > target) {
                    right--;
                    if (diff > (abs(target - sum))) {
                        Result = sum;
                        diff = abs(target - sum);
                    }
                } else {
                    left++;
                    if (diff > (abs(target - sum))) {
                        Result = sum;
                        diff = abs(target - sum);
                    }
                }
            }
        }
        cout << Result << endl;
        return Result;
    }
};