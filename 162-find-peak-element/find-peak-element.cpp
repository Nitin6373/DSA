class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int Ans = -1;

        while(low <= high){
            int Guess = (low + high)/ 2;

            if(Guess == nums.size() - 1 || (nums[Guess] > nums[Guess + 1])){
                Ans = Guess;
                high = Guess - 1;
            }
            else{
                low = Guess + 1;
            }
        }

        return Ans;
    }
};