class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int Sum = 0;
        unordered_map<int,int> f;
        f[0] = 1;
        int Res = 0 ;
        int Reminder;

        for(int i=0;i<nums.size();i++){
            Sum += nums[i];
            Reminder = Sum % k;
            if(Reminder < 0){
                Reminder += k;
            }
            Res += f[Reminder];
            f[Reminder]++;
        }
        return Res;
    }
};