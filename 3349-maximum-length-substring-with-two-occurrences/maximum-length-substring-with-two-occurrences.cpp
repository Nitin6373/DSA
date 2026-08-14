class Solution {
public:
    bool FindWrong(int s[]){
        for(int i=0;i<26;i++){
            if(s[i] > 2){
                return true;
            }
        }
        return false;
    }
    int maximumLengthSubstring(string s) {
        int fs[26] = {0};
        int low = 0;
        int high = 0;
        int len = 0;
        int res = 0;

        while (high < s.size()) {
            fs[s[high] - 97]++;

            // What to do if Wrong
            while (FindWrong(fs)) {
                fs[s[low] - 97]--;
                low++;
            }

            // Found The Right Window
            len = high - low + 1;
            res = max(len, res);
            high++;
        }

        return res;
    }
};