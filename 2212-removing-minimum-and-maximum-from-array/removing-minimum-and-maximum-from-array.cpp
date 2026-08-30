class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }

        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int Midd = (left + right) / 2;
        int Max = INT_MIN;
        int Min = INT_MAX;
        int MaxI;
        int MinI;
        int TotalDelete = INT_MAX;

        while (left <= right) {
            if (Max < nums[left]) {
                Max = nums[left];
                MaxI = left;
            }
            if (Min > nums[left]) {
                Min = nums[left];
                MinI = left;
            }

            if (Max < nums[right]) {
                Max = nums[right];
                MaxI = right;
            }
            if (Min > nums[right]) {
                Min = nums[right];
                MinI = right;
            }

            left++;
            right--;
        }

        int Front;
        int Back;
        int Both = 0;
        // First of all delete from Left
        Front = (MaxI > MinI) ? MaxI + 1 : MinI + 1;

        // Second delete both from right
        Back = (MaxI < MinI) ? n - MaxI : n - MinI;

        // Delete each from both side
        Both += (MaxI > Midd) ? n - MaxI : MaxI + 1;
        Both += (MinI > Midd) ? n - MinI : MinI + 1;

        TotalDelete = min(Front,min(Back,Both));
        return TotalDelete;
    }
};