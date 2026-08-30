class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int Sum = 0;
        int Res = 0;
        unordered_map <int,int> f;
        f[0] = 1;

        for(int i=0;i<nums.size();i++){
            Sum += nums[i];
            Res += f[Sum - k];
            f[Sum]++;
        }

        return Res;
    }
};