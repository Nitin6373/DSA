class Solution {
public:
    int FindFirst(vector<int>& arr, int t) {
        int low = 0;
        int high = arr.size() - 1;
        int Ans = -1;

        while (low <= high) {
            int Guess = (low + high) / 2;

            if (arr[Guess] > t) {
                high = Guess - 1;
            } else if (arr[Guess] < t){
                low = Guess + 1;
            }
            else {
                Ans = Guess;
                high = Guess - 1;
            }
        }

        return Ans;
    }

    int FindSec(vector<int>& arr, int t) {
        int low = 0;
        int high = arr.size() - 1;
        int Ans = -1;

        while (low <= high) {
            int Guess = (low + high) / 2;

            if (arr[Guess] > t) {
                high = Guess - 1;
            } else if (arr[Guess] < t){
                low = Guess + 1;
            }
            else {
                Ans = Guess;
                low = Guess + 1;
            }
        }

        return Ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int First = FindFirst(nums, target);
        int Sec = FindSec(nums, target);

        return {First, Sec};
    }
};