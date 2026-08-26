class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int low = 0;
        int high = 0;
        int fs[2] = {0};
        int Res = INT_MAX;
        int len = 0;
        string Ans = "";
        while (high < s.size()) {
            fs[s[high] - 48]++;

            while (fs[1] == k) {
                len = high - low + 1;
                if (Res > len) {
                    Ans = s.substr(low, len);
                    Res = len;
                } else if (Res == len) {
                    string Temp = s.substr(low, len);
                    if (Temp < Ans) {
                        Ans = Temp;
                    }
                }
                fs[s[low] - 48]--;
                low++;
            }
            high++;
        }
        return Ans;
    }
};