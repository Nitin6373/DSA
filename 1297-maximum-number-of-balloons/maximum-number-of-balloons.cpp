class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> f;

        for (int i = 0; i < text.size(); i++) {
            f[text[i]]++;
        }

        int Count_Balloon = 0;

        while (true) {
            if (f['b'] >= 1 && f['a'] >= 1 && f['l'] >= 2 && f['o'] >= 2 && f['n'] >= 1) {
                f['b'] -= 1;
                f['a'] -= 1;
                f['l'] -= 2;
                f['o'] -= 2;
                f['n'] -= 1;
                Count_Balloon++;
            } else {
                break;
            }
        }

        return Count_Balloon;
    }
};