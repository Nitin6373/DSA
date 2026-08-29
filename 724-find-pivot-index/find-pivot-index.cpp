class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int Left = 0;
        int Right = 0;
        int Sum = 0;

        
        for(int i=0;i<nums.size();i++){
            Sum += nums[i];
        }
        
        if((Sum - nums[0]) == 0){
            return 0;
        }

        for(int i=1;i<nums.size();i++){
            Left += nums[i-1];
            Right = Sum - Left - nums[i];

            if(Left == Right){
                return i;
            }
        }

        
        return -1;
    }
};
