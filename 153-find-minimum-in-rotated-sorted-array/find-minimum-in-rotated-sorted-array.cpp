class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1;
        int Ans = 0;

        while(low <= high){
            int Guess = (low + high) / 2;

            if(nums[Guess] > nums[Ans]){
                low = Guess + 1;
            }
            else{
                Ans = Guess;
                high = Guess - 1;
            }
        }

        return nums[Ans];
    }
};