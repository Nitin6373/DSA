class Solution {
public:
    bool Helper(int m, int n, int k, int g) { 
        int Row = m;
        int Col = 1;
        int Count = 0;

        while (Row > 0 && Col <= n) {
            if ((Row * Col) > g)
                Row--;
            else {
                Count += Row;
                Col++;
            }
        }

        if(Count >= k)
            return true;

        return false;
    }
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        int Res = -1;

        while (low <= high) {
            int guess = (low + high) / 2;

            if (Helper(m, n, k, guess)) {
                Res = guess;
                high = guess - 1;
            } else {
                low = guess + 1;
            }
        }

        return Res;
    }
};