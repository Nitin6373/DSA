class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int Max = nums[0];
        int Min = nums[0];
        int MaxRes = nums[0];
        int MinRes = nums[0];
        int Sum = nums[0];

        for(int i=1;i<nums.size();i++){

            int v1 = nums[i];
            int v2 = Max + nums[i];
            int v3 = Min + nums[i];

            Max = max(v1 , max(v2,v3));
            Min = min(v1 , min(v2,v3));
            MaxRes = max(MaxRes,Max);
            MinRes = min(MinRes,Min);
            Sum += nums[i];
        }
        if(MaxRes < 0){
            return MaxRes;
        }
        int Res = max(MaxRes,(Sum - MinRes));
        return Res;
    }
};