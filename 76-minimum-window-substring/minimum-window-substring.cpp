class Solution {
public:
    bool Check(int at[], int as[]) {
        for (int i = 0; i < 256; i++) {
            if (at[i] > as[i]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int low = 0;
        int high = 0;
        int len = 0;
        int start =0;
        int res = INT_MAX;
        int fs[256] = {0};
        int ft[256] = {0};

        for (int i = 0; i < t.size(); i++) {
            ft[t[i]]++;
        }

        for (high = 0; high < s.size(); high++) {
            fs[s[high]]++;

            while (Check(ft, fs)) {
                len = high - low + 1;
                if (res > len) {
                    start = low;
                    res = len;
                }
                fs[s[low]]--;
                low++;
            }
        }

        if(res == INT_MAX){
            return "";
        }
        else{
            return s.substr(start,res);
        }
    }
};