class Solution {
public:
    int findMaxCount(vector<int>& arr) {
        int max = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
    int characterReplacement(string s, int k) {
        int low = 0;
        int high = 0;
        int len = 0;
        int res = 0;
        int MaxCount = 0;
        int diff = 0;
        vector<int> freq(26, 0);

        for (high = 0; high < s.size(); high++) {
            freq[s[high] - 'A']++;

            // Intial value of len , diff , maxcount
            len = high - low + 1;
            MaxCount = findMaxCount(freq);
            diff = len - MaxCount;

            // Execute till window contain wrong info
            while (diff > k) {
                freq[s[low] - 'A']--;
                low++;

                // Window is changed , so does the variable len, max , diff
                len = high - low + 1;
                MaxCount = findMaxCount(freq);
                diff = len - MaxCount;
            }

            // if Execution is made it this far means now the diff is either less or equal to k

            len = high-low+1;
            res = max(len,res);
        }
        return res;
    }
};