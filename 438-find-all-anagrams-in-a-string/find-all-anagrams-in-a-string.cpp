class Solution {
public:
    bool Sahi(int s[], int p[]) {
        for (int i = 0; i < 26; i++) {
            if (s[i] != p[i]) {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        
        int low = 0;
        int high = p.size() - 1;
        vector<int> Ans;
        int fs[26] = {0};
        int fp[26] = {0};

        if(p.size() > s.size())
          return Ans;

        for (int i = 0; i < p.size(); i++) {
            fp[p[i] - 97]++;
        }

        for (int i = low; i <= high; i++) {
            fs[s[i] - 97]++;
        }

        while (high < s.size()) {
            if (Sahi(fs, fp)) {
                Ans.push_back(low);
            }
            high++;
            if (high < s.size())
                fs[s[high] - 97]++;
            fs[s[low] - 97]--;
            low++;
        }
        return Ans;
    }
};