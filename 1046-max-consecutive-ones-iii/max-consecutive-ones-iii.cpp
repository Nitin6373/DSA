class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Regular
        int low = 0;
        int high = 0;
        int len = 0;
        int res = 0;

        // Needed
        int diff = 0;
        int freqOne = 0;
        vector<int> freq(2, 0);

        for (high = 0; high < nums.size(); high++) {
            freq[nums[high]]++;

            // Initial value of needed utilities
            len = high - low + 1;
            freqOne = freq[1];
            diff = len - freqOne;

            // Wrong Case
            while (diff > k) {
                freq[nums[low]]--;
                low++;

                // REcalculate
                len = high - low + 1;
                freqOne = freq[1];
                diff = len - freqOne;
            }

            // Right Case
            len = high - low + 1;
            res = max(len, res);
        }
        return res;
    }
};