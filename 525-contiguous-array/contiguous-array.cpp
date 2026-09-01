class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int Zero = 0;
        int One = 0;
        int diff = 0;
        int Res = 0;
        unordered_map<int, int> f;

        for (int i = 0; i < nums.size(); i++) {
            (nums[i]) ? One++ : Zero++;

            diff = Zero - One;

            if (diff == 0) {
                Res = max(Res, i + 1);
            }

            if (f.find(diff) == f.end()) {
                f[diff] = i;
            } else {
                Res = max(Res, (i - f[diff]));
            }
        }

        return Res;
    }
};