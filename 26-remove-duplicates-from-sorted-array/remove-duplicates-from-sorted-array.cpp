class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int officer = 0;
    int N = nums.size();
    int CM = officer + 1;
    int Unique = 1;

    while (CM < N)
    {
        if (nums[officer] == nums[CM])
        {
            CM++;
        }
        else
        {
            nums[++officer] = nums[CM];
            Unique++;
            CM++;
        }
    }
    return Unique;
    }
};