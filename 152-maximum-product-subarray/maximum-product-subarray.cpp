class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int Best = nums[0];
        int Worst = nums[0];
        int Res = nums[0];

        for(int i=1;i<nums.size();i++){

            int v1 = nums[i];
            int v2 = Best * nums[i];
            int v3 = Worst * nums[i];

            Best = max(v1,max(v2,v3));
            Worst = min(v1,min(v2,v3));
            Res = max(Res,max(Best,Worst));
        }
        return Res;
    }
};