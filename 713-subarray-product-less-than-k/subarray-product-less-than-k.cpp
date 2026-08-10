class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        long long product = 1;
        int count = 0;

        if(k <= 1){
            return 0;
        }
        while (high < nums.size()) {
            product *= nums[high];

            while(product >= k){
                // Wrong Case
                product = product / nums[low];
                low++;
            }

            count += high - low + 1;
            high++;
        }
        return count;
    }
};