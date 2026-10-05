class Solution {
public:
    bool MakeBouquets(vector<int>& arr, int G, int M, int k) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= G) {
                count++;
                if (count == k) {
                    M--;
                    count = 0;
                    if(M == 0)  
                        break;
                }
                continue;
            }
            count = 0;
        }
        if(M == 0){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > (long long)bloomDay.size())
            return -1;
        int MinDay = INT_MAX;
        int MaxDay = INT_MIN;

        for (int i = 0; i < bloomDay.size(); i++) {
            MinDay = min(MinDay, bloomDay[i]);
            MaxDay = max(MaxDay, bloomDay[i]);
        }

        int low = MinDay;
        int high = MaxDay;
        int Ans = -1;

        while (low <= high) {
            int Guess = (low + high) / 2;
            if (MakeBouquets(bloomDay, Guess, m, k)) {
                Ans = Guess;
                high = Guess - 1;
            } else {
                low = Guess + 1;
            }
        }

        return Ans;
    }
};