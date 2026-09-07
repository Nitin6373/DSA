class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {

        int First = 0;
        int Second = 0;
        int Start1 = 0;
        int Start2 = 0;
        int End1 = 0;
        int End2 = 0;
        vector<vector<int>> Res;

        while (First < firstList.size() && Second < secondList.size()) {
            Start1 = firstList[First][0];
            End1 = firstList[First][1];

            Start2 = secondList[Second][0];
            End2 = secondList[Second][1];

            if (Start1 <= Start2) {
                if (End1 >= Start2) {
                    Res.push_back({max(Start1, Start2), min(End1, End2)});
                }
            } else {
                if (End2 >= Start1) {
                    Res.push_back({max(Start1, Start2), min(End1, End2)});
                }
            }
            (End1 <= End2) ? First++ : Second++;
        }
        return Res;
    }
};