class Solution {
public:
    bool Helper(vector<int>&a,int g,int k){
        int group = 1;
        int Sum = 0;
        for(int i=0;i<a.size();i++){
            Sum += a[i];
            if(Sum > g){
                group++;
                Sum = a[i];
            }
        }
        if(group <= k)
            return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k > nums.size())
            return false;

        int Total = 0;
        int Max = 0;
        for(int i=0;i<nums.size();i++){
            Total += nums[i];
            Max = max(Max,nums[i]);
        }

        int low = Max;
        int high = Total;
        int Ans = -1;

        while(low<=high){
            int Guess = (low + high) / 2;
            if(Helper(nums,Guess,k)){
                Ans = Guess;
                high = Guess - 1;
            }
            else{
                low = Guess + 1;
            }
        }

        return Ans;
    }
};