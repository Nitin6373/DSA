class Solution {
public:
    bool helper(vector<int>& arr, int G) {
        int Count = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= G) {
                Count++;
            }
        }

        if (Count >= G)
            return true;
        return false;
    }

    int hIndex(vector<int>& citations) {
        int low = 0;
        int high = citations.size();
        int Ans = -1;

        while (low <= high) {
            int Guess = (low + high) / 2;
            if (helper(citations, Guess)) {
                Ans = Guess;
                low = Guess + 1;
            } else {
                high = Guess - 1;
            }
        }
        return Ans;
    }
};