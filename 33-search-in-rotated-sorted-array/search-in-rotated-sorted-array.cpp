class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int guess = (low + high) / 2;

            if(nums[guess] == target)
                return guess;

            if(nums[0] <= nums[guess]){
                // Part 1
                if(nums[guess] < target){
                    low = guess + 1;
                }
                else{
                    if(nums[0] > target){
                        low = guess + 1;
                    }
                    else{
                        high = guess-1;
                    }
                }
            }
            else{
                if(nums[guess] > target){
                    high = guess - 1;
                }
                else{
                    if(target <= nums[nums.size() - 1]){
                        low = guess + 1;
                    }
                    else{
                        high = guess - 1;
                    }
                }
            }
        }

        return -1;
    }
};