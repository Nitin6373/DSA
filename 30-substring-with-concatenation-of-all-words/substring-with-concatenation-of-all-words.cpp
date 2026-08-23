class Solution {
public:
    bool Find(unordered_map<string, int>& window,
              unordered_map<string, int>& word) {
        for (auto& element : word) {
            if (window[element.first] != element.second)
                return false;
        }

        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> Res = {};

        if (words.size() == 0 || s.size() == 0 ||
            s.size() < (words[0].size() * words.size()))
            return Res;

        int low = 0;
        int high = 0;
        int ChildLow;
        int ChildHigh;

        unordered_map<string, int> map_words;
        unordered_map<string, int> map_window;

        // First of all count the frequency of each word in words
        for (int i = 0; i < words.size(); i++) {
            map_words[words[i]]++;
        }

        for (int it = 0; it < words[0].size(); it++) {
            map_window.clear();
            low = it;
            high = ((words[0].size() * words.size()) - 1) + low;
            while (high < s.size()) {
                // Addding Frequency of the first window's words
                if (it == low) {
                    // For Calculating The Frequency in the first window for
                    // each of the word
                    ChildLow = low;
                    ChildHigh = low + words[0].size() - 1;

                    while (ChildHigh <= high) {
                        map_window[s.substr(ChildLow, words[0].size())]++;
                        ChildHigh += words[0].size();
                        ChildLow += words[0].size();
                    }
                } else {
                    // Include High IN info
                    map_window[s.substr(high - words[0].size() + 1,
                                        words[0].size())]++;

                    // remove low from the info
                    map_window[s.substr(low - words[0].size(),
                                        words[0].size())]--;
                    if (map_window[s.substr(low - words[0].size(),
                                            words[0].size())] == 0) {
                        map_window.erase(
                            s.substr(low - words[0].size(), words[0].size()));
                    }
                }
                // Check : Window is right or not
                if (Find(map_window, map_words)) {
                    Res.push_back(low);
                }

                // Slide The Window
                low += words[0].size();
                high += words[0].size();
            }
        }

        return Res;
    }
};