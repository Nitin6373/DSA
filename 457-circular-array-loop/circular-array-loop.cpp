class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int Slow = 0;
        int Fast = 0;
        char Sign = ' ';
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            Slow = i;
            Fast = i;
            Sign = (nums[i] < 0) ? '-' : '+';

            while (1) {
                Slow = ((Slow + nums[Slow]) % n + n) % n;

                Fast = ((Fast + nums[Fast]) % n + n) % n;

                if ((Sign == '-' && (nums[Fast] >= 0 || nums[Slow] >= 0)) ||
                    (Sign == '+' && (nums[Slow] < 0 || nums[Fast] < 0))) {
                    break;
                }

                Fast = ((Fast + nums[Fast]) % n + n) % n;

                if ((Sign == '-' && nums[Fast] >= 0) ||
                    (Sign == '+' && nums[Fast] < 0)) {
                    break;
                }

                if (Slow == Fast) {
                    int c = Fast;
                    Fast = ((Fast + nums[Fast]) % n + n) % n;

                    if (c == Fast) {
                        break;
                    }

                    return true;
                }
            }
        }

        return false;
    }
};