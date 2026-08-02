class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> Neg;
        vector<int> Pos;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                // Push in Positive Array
                Pos.push_back(nums[i]);
            } else {
                // Push In Negative Array
                Neg.push_back(nums[i]);
            }
        }
        if (Neg.size() == 0) {
            // It Means Array Is Fully Positive
            for (int i = 0; i < nums.size(); i++) {
                // Add The Square In Main Array
                nums[i] = nums[i] * nums[i];
            }
            return nums;
        }
        if (Pos.size() == 0) {
            // It Means Whole Array is Negative
            for (int i = 0; i < nums.size(); i++) {
                // Add The Square In Main Array
                nums[i] = nums[i] * nums[i];
            }
            reverse(nums.begin(), nums.end());
            return nums;
        }

        // Make Square of Both Array

        // Negative
        for (int i = 0; i < Neg.size(); i++) {
            // Add The Square In Negative Array
            Neg[i] = Neg[i] * Neg[i];
        }
        reverse(Neg.begin(), Neg.end());

        // Positive
        for (int i = 0; i < Pos.size(); i++) {
            // Add The Square In Positive Array
            Pos[i] = Pos[i] * Pos[i];
        }

        vector<int> Res;
        int i = 0;
        int j = 0;

        while (i < Neg.size() && j < Pos.size()) {
            if (Neg[i] <= Pos[j]) {
                Res.push_back(Neg[i]);
                i++;
            } else {
                Res.push_back(Pos[j]);
                j++;
            }
        }

        while (i < Neg.size()) {
            Res.push_back(Neg[i]);
            i++;
        }
        while (j < Pos.size()) {
            Res.push_back(Pos[j]);
            j++;
        }

        return Res;
    }
};