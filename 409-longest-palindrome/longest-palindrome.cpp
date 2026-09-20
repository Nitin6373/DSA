class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> fs;
        int Odd = 0;
        int OddFreq = 0;
        int EvenFreq = 0;

        for (int i = 0; i < s.size(); i++) {
            fs[s[i]]++;
        }

        for (auto i : fs) {
            int freq = i.second;
            if (freq % 2 != 0) {
                // Odd
                Odd++;
                OddFreq += freq;
            }else{
                // Even
                EvenFreq += freq;
            }
        }

        if(Odd <= 1)
            return s.size();

        Odd--;
        return EvenFreq + (OddFreq - Odd);
    }
};