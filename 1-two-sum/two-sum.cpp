class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> fs;

        for(int i=0;i<nums.size();i++){
            int find = target - nums[i];
            if(fs.find(find) == fs.end()){
                fs[nums[i]] = i;
            }
            else{
                return {fs[find],i};
            }
        }
        return {-1,-1};
    }
};