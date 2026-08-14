class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> Ans;
        if (nums.size() < 4)
            return Ans;
        sort(nums.begin(), nums.end());
        long long sum;
        long long k;
        int Third;
        int Fourth;
        for (int First = 0; First < nums.size() - 3; First++) {
            if (First > 0 && nums[First] == nums[First - 1] &&
                First < nums.size() - 3) {
                continue;
            }

            for (int Second = First + 1; Second < nums.size() - 2; Second++) {
                if (Second > First + 1 && nums[Second] == nums[Second - 1] &&
                    Second < nums.size() - 2) {
                    continue;
                }
                sum = nums[First] + nums[Second];
                k = target - sum;
                Third = Second + 1;
                Fourth = nums.size() - 1;

                while (Third < Fourth) {
                    if ((nums[Third] + nums[Fourth]) == k) {
                        Ans.push_back({nums[First], nums[Second], nums[Third],
                                       nums[Fourth]});
                        Third++;
                        Fourth--;
                        while (Third < Fourth &&
                               (nums[Third] == nums[Third - 1])) {
                            Third++;
                        }
                        while (Third < Fourth &&
                               (nums[Fourth] == nums[Fourth + 1])) {
                            Fourth--;
                        }
                    } else if ((nums[Third] + nums[Fourth]) >= k) {
                        Fourth--;
                    } else {
                        Third++;
                    }
                }
            }
        }
        return Ans;
    }
};