class Solution {
public:
    bool Find(int s[], int s2[]) {
        for (int i = 0; i < 26; i++) {
            if (s[i] != s2[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {

        int low = 0;
        int high = s1.size() - 1;
        int fs1[26] = {0};
        int fs2[26] = {0};

        for (int i = 0; i < s1.size(); i++) {
            fs1[s1[i] - 97]++;
        }

        while (high < s2.size()) {
            if (high == s1.size() - 1) {
                for (int i = 0; i <= high; i++) {
                    fs2[s2[i] - 97]++;
                }
            }

            if (Find(fs1, fs2)) {
                return true;
            }
            high++;
            if (high < s2.size())
                fs2[s2[high] - 97]++;
            fs2[s2[low] - 97]--;
            low++;
        }

        return false;
    }
};