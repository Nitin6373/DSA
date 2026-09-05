class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());

        int Start1 = intervals[0][0];
        int End1 = intervals[0][1];
        vector<vector<int>> Res;


        for(int i=1;i<intervals.size();i++){
            int Start2 = intervals[i][0];
            int End2 = intervals[i][1];
            if(End1 >= Start2){
                Start1 = Start1;
                End1 = max(End1,End2);
            }
            else{
                Res.push_back({Start1,End1});
                Start1 = Start2;
                End1 = End2;
            }
        }
        Res.push_back({Start1,End1});
        return Res;
    }
};