class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums[0] == target)
            return 0;
        else {
            if(nums.size() == 1){
                return -1;
            }
        }

        int Min = 0;

        int low = 1;
        int high = nums.size() - 1;

        while (low <= high) {
            int Guess = (low + high) / 2;

            if (nums[Guess] > nums[Min]) {
                low = Guess + 1;
            } else {
                Min = Guess;
                high = Guess - 1;
            }
        }

        if(Min == 0){
            low = 0;
            high = nums.size() -1 ;

            while(low <= high){
                int Guess = (low + high) / 2;

                if(nums[Guess] == target){
                    return Guess;
                }
                if(nums[Guess] > target){
                    high = Guess - 1;
                }
                else{
                    low = Guess + 1;
                }
            }
        }
        else if(nums[0] > target){
            // Binary Search in Chota Part

            low = Min;
            high = nums.size() - 1;

            while(low <= high){
                int Guess = (low + high) / 2;

                if(nums[Guess] == target){
                    return Guess;
                }
                if(nums[Guess] > target){
                    high = Guess - 1;
                }
                else{
                    low = Guess + 1;
                }
            }
        }
        else{
            // Binary Search in Bada Part
            
            low = 0;
            high = Min - 1;

            while(low <= high){
                int Guess = (low + high) / 2;

                if(nums[Guess] == target){
                    return Guess;
                }
                if(nums[Guess] > target){
                    high = Guess - 1;
                }
                else{
                    low = Guess + 1;
                }
            }
        }
        return -1;
    }
};