class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int high = 0;
        int res = 0;
        int len = 0;
        unordered_map<int,int> f;
        while(high < s.size()){
            f[s[high]]++;
            while(f[s[high]] == 2){
                f[s[low]]--;
                if(f[s[low]] == 0){
                    f.erase(s[low]);
                }
                low++;
            }
            len = high - low + 1;
            res = max(len,res);
            high++;
        }
        return res;
    }
};