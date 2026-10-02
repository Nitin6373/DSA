class Solution {
public:
    long long FindTotalHourAtKSpeed(vector<int>& piles, int k) {
        long long Res = 0;
        for (int i = 0; i < piles.size(); i++) {
            Res += piles[i] / k;
            if (piles[i] % k != 0) {
                Res++;
            }
        }
        return Res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        int Ans = -1;

        for (int i = 0; i < piles.size(); i++) {
            high = max(high, piles[i]);
        }

        while (low <= high) {
            int Guess = (low + high) / 2;

            long long Total = FindTotalHourAtKSpeed(piles, Guess);

            if (Total <= h) {
                Ans = Guess;
                high = Guess - 1;
            } else {
                low = Guess + 1;
            }
        }

        return Ans;
    }
};