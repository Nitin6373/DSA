class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int MaxEnd = nums[0];
        int MinEnd = nums[0];
        int Res = abs(nums[0]);

        for(int i=1;i<nums.size();i++){

            int v1 = nums[i];
            int v2 = MaxEnd + nums[i];
            int v3 = MinEnd + nums[i];

            MaxEnd = max(v1,max(v2 ,v3));
            MinEnd = min(v1,min(v2,v3));
            Res = max(Res,max(abs(MaxEnd),abs(MinEnd)));
        }
        return Res;
    }
};